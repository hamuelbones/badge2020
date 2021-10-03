
#include "game.h"
#include <stddef.h>

// Load a level structure into the game structure and reset position, etc.
void soko_game_load_level(SOKOBAN_GAME *sokoban, const SOKOBAN_LEVEL *level) {
    sokoban->moves = 0;
    sokoban->pushes = 0;
    sokoban->player_location = level->player_start;
    sokoban->level_focus = level->player_start;
    for (int i=0; i<level->num_boxes; i++) {
        sokoban->box_locations[i] = level->box_coords[i];
    }
    sokoban->level = level;
}

// Check if there is a wall at map coordinates.
bool soko_game_is_wall_at_loc(const SOKOBAN_LEVEL *level, SOKOBAN_COORDS loc) {

    // Round up if not byte-aligned. New rows always start on new bytes
    unsigned int row_byte_size = (level->level_size.x + 7) / 8;
    unsigned int map_index = row_byte_size * loc.y + loc.x / 8;
    // Bits are encoded MS first.
    unsigned int map_bit = 7 - loc.x % 8;

    if (map_index < 0 || map_index >= (row_byte_size * level->level_size.y)) {
        return true;
    }

    return (bool) (level->map[map_index] & (1<<map_bit));
}

// Check if there is a box here. Return coordinate structure if there is, which
// can be moved, otherwise return NULL.
SOKOBAN_COORDS* soko_game_get_box_at_loc(SOKOBAN_GAME *ctx, SOKOBAN_COORDS loc) {
    for (int i=0; i<ctx->level->num_boxes; i++) {

        if ((loc.x == ctx->box_locations[i].x) && (loc.y == ctx->box_locations[i].y)) {
            return &ctx->box_locations[i];
        }
    }
    return NULL;
}

// Check if there is a goal at the map coordinates.
bool soko_game_is_goal_at_loc(const SOKOBAN_LEVEL *level, SOKOBAN_COORDS loc) {

    for (int i=0; i<level->num_boxes; i++) {
        if ((loc.x == level->goal_coords[i].x) && (loc.y == level->goal_coords[i].y)) {
            return true;
        }
    }
    return false;
}


bool soko_game_coordinate_in_map(const SOKOBAN_LEVEL *level, SOKOBAN_COORDS map_loc) {
    return (map_loc.x >=0 && map_loc.x < level->level_size.x &&
            map_loc.y >=0 && map_loc.y < level->level_size.y);
}

bool soko_is_solved(SOKOBAN_GAME *game) {
    for (int box_i = 0; box_i<game->level->num_boxes; box_i++) {
        SOKOBAN_COORDS box_location = game->box_locations[box_i];
        bool matched = false;
        for (int goal_i = 0; goal_i<game->level->num_boxes; goal_i++) {
            if (box_location.x == game->level->goal_coords[goal_i].x &&
                box_location.y == game->level->goal_coords[goal_i].y) {
                matched = true;
                break;
            }
        }
        if (!matched) {
            return false;
        }
    }
    return true;
}

void soko_game_bound_focus(SOKOBAN_GAME *game) {

    int dx, dy;
    dx = game->level_focus.x - game->player_location.x;
    dy = game->level_focus.y - game->player_location.y;

    const int8_t max_dist_from_center = 2;

    if (dx < -max_dist_from_center) {
        game->level_focus.x = game->player_location.x - max_dist_from_center;
    } else if (dx > max_dist_from_center) {
        game->level_focus.x = game->player_location.x + max_dist_from_center;
    }

    if (dy <= -max_dist_from_center) {
        game->level_focus.y = game->player_location.y - max_dist_from_center;
    } else if (dy >= max_dist_from_center) {
        game->level_focus.y = game->player_location.y + max_dist_from_center;
    }
}

bool soko_game_move(SOKOBAN_GAME *game, MOVE_DIRECTION dir) {

    int16_t dx = 0, dy = 0;
    SOKOBAN_COORDS new_coords = game->player_location;
    switch (dir) {
        case MOVE_UP:
            dy = -1;
            break;
        case MOVE_DOWN:
            dy = 1;
            break;
        case MOVE_LEFT:
            dx = -1;
            break;
        case MOVE_RIGHT:
            dx = 1;
            break;
        default:
            return false;
    }

    new_coords.x += dx;
    new_coords.y += dy;

    if (soko_game_is_wall_at_loc(game->level, new_coords)) {
        return false;
    }

    SOKOBAN_COORDS *box_to_push = soko_game_get_box_at_loc(game, new_coords);
    if (!box_to_push) {
        game->player_location = new_coords;
        game->moves++;
        soko_game_bound_focus(game);
        return true;
    }

    // Location we want to move to has a box.
    // Is box location movable?
    SOKOBAN_COORDS new_box_coords = new_coords;
    new_box_coords.x += dx;
    new_box_coords.y += dy;

    if (soko_game_is_wall_at_loc(game->level, new_box_coords)) {
        return false;
    }

    if (!soko_game_get_box_at_loc(game, new_box_coords)) {
        *box_to_push = new_box_coords;
        game->player_location = new_coords;
        game->moves++;
        game->pushes++;
        soko_game_bound_focus(game);
        return true;
    }

    return false;
}
