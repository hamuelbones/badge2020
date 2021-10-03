//
// Created by Samuel Jones on 9/29/21.
//
#include "draw.h"
#include "tile.h"
#include "game.h"
#include <printf.h>

#ifdef __linux__
#include "../linux/linuxcompat.h"
#else
#include "colors.h"
#include "menu.h"
#include "buttons.h"
#endif

static void _soko_draw_tile(const TILE* t, SOKOBAN_COORDS base_xy) {
    // only 2 bit palettes implemented for now
    int next_byte_countdown = 4;
    uint8_t current_byte = t->data[0];
    uint32_t current_index = 0;
    for (int y=0; y<t->x; y++) {
        for (int x=0; x<t->y; x++) {

            if (!next_byte_countdown) {
                next_byte_countdown = 4;
                current_byte = t->data[++current_index];
            }

            uint8_t color_idx = current_byte & 0x03;
            //printf("%u, %u, %u, %u\n", x, y, color_idx, next_byte_countdown);
            uint16_t color = t->palette[color_idx];

            current_byte >>= 2;
            next_byte_countdown -= 1;

            if (color == SKIP_PIXEL) {
                continue;
            }
            FbColor(color);
            FbPoint(base_xy.x + x, base_xy.y + y);
        }
    }
}

SOKOBAN_COORDS soko_draw_get_draw_location(SOKOBAN_COORDS focus, SOKOBAN_COORDS map_loc) {
    SOKOBAN_COORDS draw_loc = {
        .x = (SOKO_TILES_X/2) - focus.x + map_loc.x,
        .y = (SOKO_TILES_Y/2) - focus.y + map_loc.y
    };
    return draw_loc;
}

SOKOBAN_COORDS soko_draw_get_map_location(SOKOBAN_COORDS focus, SOKOBAN_COORDS draw_loc) {
    SOKOBAN_COORDS map_loc = {
            .x = focus.x - (SOKO_TILES_X/2)  + draw_loc.x,
            .y = focus.y - (SOKO_TILES_Y/2)  + draw_loc.y,
    };
    return map_loc;
}

static SOKOBAN_COORDS _get_fb(SOKOBAN_COORDS draw_loc) {
    SOKOBAN_COORDS xy = {
            draw_loc.x * SOKO_TILESIZE_X + SOKO_PADDING_X,
            draw_loc.y * SOKO_TILESIZE_Y + SOKO_PADDING_Y
    };
    return xy;
}


bool soko_draw_is_drawable(SOKOBAN_COORDS focus, SOKOBAN_COORDS loc, SOKOBAN_COORDS* map_loc) {
    SOKOBAN_COORDS tile_loc = soko_draw_get_draw_location(focus, loc);

    if (tile_loc.x >= 0 && tile_loc.x < SOKO_TILES_X &&
        tile_loc.y >= 0 && tile_loc.y < SOKO_TILES_Y) {
        if (map_loc) {
            *map_loc = tile_loc;
        }
        return true;
    }
    return false;
}

void soko_draw_player(SOKOBAN_COORDS focus, SOKOBAN_COORDS loc) {
    SOKOBAN_COORDS draw_loc;
    if (!soko_draw_is_drawable(focus, loc, &draw_loc)) {
        return;
    }
    SOKOBAN_COORDS xy = _get_fb(draw_loc);
    _soko_draw_tile(soko_tile_get(TILE_PLAYER), xy);
    //FbWriteLine("@");
}

void soko_draw_wall(SOKOBAN_COORDS focus, SOKOBAN_COORDS loc) {
    SOKOBAN_COORDS draw_loc;
    if (!soko_draw_is_drawable(focus, loc, &draw_loc)) {
        return;
    }
    SOKOBAN_COORDS xy = _get_fb(draw_loc);
    _soko_draw_tile(soko_tile_get(TILE_WALL), xy);
    //FbWriteLine("#");
}

void soko_draw_box(SOKOBAN_COORDS focus, SOKOBAN_COORDS loc) {
    SOKOBAN_COORDS draw_loc;
    if (!soko_draw_is_drawable(focus, loc, &draw_loc)) {
        return;
    }
    SOKOBAN_COORDS xy = _get_fb(draw_loc);
    _soko_draw_tile(soko_tile_get(TILE_BOX), xy);
    //FbWriteLine("B");
}

void soko_draw_goal(SOKOBAN_COORDS focus, SOKOBAN_COORDS loc) {
    SOKOBAN_COORDS draw_loc;
    if (!soko_draw_is_drawable(focus, loc, &draw_loc)) {
        return;
    }
    SOKOBAN_COORDS xy = _get_fb(draw_loc);
    _soko_draw_tile(soko_tile_get(TILE_GOAL), xy);
    //FbWriteLine("G");
}

void soko_draw_game(SOKOBAN_GAME *game) {

    // 132 by 132 screen - with 8x8 tiles, let's use 15 tiles vertically and 15 horizontally, saving the bottom tile row
    // for a line of text. That provides 2 px buffer on the top and 6 px on the sides

    FbClear();
    // Draw walls
    SOKOBAN_COORDS draw_base = {0, 0};
    SOKOBAN_COORDS map_base = soko_draw_get_map_location(game->level_focus, draw_base);

    for (int y=0; y<15; y++) {
        for (int x=0; x<15; x++) {

            SOKOBAN_COORDS map_tile = {
                    .x = (int16_t)(x + map_base.x),
                    .y = (int16_t)(y + map_base.y),
            };

            if (!soko_game_coordinate_in_map(game->level, map_tile)) {
                continue;
            }

            if (soko_game_is_wall_at_loc(game->level, map_tile)) {
                soko_draw_wall(game->level_focus, map_tile);
                continue;
            }
        }
    }

    // Draw goals
    for (int i=0; i<game->level->num_boxes; i++) {
        soko_draw_goal(game->level_focus, game->level->goal_coords[i]);
    }

    // Draw boxes
    for (int i=0; i<game->level->num_boxes; i++) {
        soko_draw_box(game->level_focus, game->box_locations[i]);
    }

    // Render player
    soko_draw_player(game->level_focus, game->player_location);

    //Render game stats
    FbColor(WHITE);
    char text_data[12];
    FbMove(SOKO_PADDING_X, 16*SOKO_TILESIZE_Y-5);
    snprintf(text_data, 12, "L%u", game->level_index+1);
    FbWriteLine(text_data);

    FbMove(SOKO_PADDING_X+SOKO_TILESIZE_X*3, 16*SOKO_TILESIZE_Y-5);
    snprintf(text_data, 12, "M:%u", game->moves);
    FbWriteLine(text_data);

    FbMove(SOKO_PADDING_X+SOKO_TILESIZE_X*9, 16*SOKO_TILESIZE_Y-5);
    snprintf(text_data, 12, "P:%u", game->pushes);
    FbWriteLine(text_data);

    FbSwapBuffers();
}
