//
// Created by Samuel Jones on 9/29/21.
//

#ifndef SOKOBAN_DRAW_H
#define SOKOBAN_DRAW_H

#include "types.h"
#include <stdbool.h>

bool soko_draw_is_drawable(SOKOBAN_COORDS focus, SOKOBAN_COORDS loc,
                           SOKOBAN_COORDS *draw_loc);


SOKOBAN_COORDS soko_draw_get_draw_location(SOKOBAN_COORDS focus, SOKOBAN_COORDS map_loc);
SOKOBAN_COORDS soko_draw_get_map_location(SOKOBAN_COORDS focus, SOKOBAN_COORDS draw_loc);

// Drawing functions. Returns early without doing anything if the tile
// is not drawable given its map position and the game focus point.
void soko_draw_player(SOKOBAN_COORDS focus, SOKOBAN_COORDS loc);
void soko_draw_wall(SOKOBAN_COORDS focus, SOKOBAN_COORDS loc);
void soko_draw_box(SOKOBAN_COORDS focus, SOKOBAN_COORDS loc);
void soko_draw_goal(SOKOBAN_COORDS focus, SOKOBAN_COORDS loc);
void soko_draw_box_in_goal(SOKOBAN_COORDS focus, SOKOBAN_COORDS loc);

void soko_draw_game(SOKOBAN_GAME *game);

#endif //SOKOBAN_DRAW_H
