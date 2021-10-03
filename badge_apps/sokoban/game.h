
#ifndef SOKOBAN_GAME_H
#define SOKOBAN_GAME_H

#include <stdint.h>
#include <stdbool.h>
#include "types.h"

void soko_game_load_level(SOKOBAN_GAME *sokoban, const SOKOBAN_LEVEL *level);

// Location checking functions.

bool soko_game_is_wall_at_loc(const SOKOBAN_LEVEL *level, SOKOBAN_COORDS map_loc);
SOKOBAN_COORDS* soko_game_get_box_at_loc(SOKOBAN_GAME *game, SOKOBAN_COORDS map_loc);
bool soko_game_is_goal_at_loc(const SOKOBAN_LEVEL *level, SOKOBAN_COORDS map_loc);
bool soko_game_coordinate_in_map(const SOKOBAN_LEVEL *level, SOKOBAN_COORDS draw_loc);
bool soko_is_solved(SOKOBAN_GAME *game);

void soko_game_bound_focus(SOKOBAN_GAME *game);
bool soko_game_move(SOKOBAN_GAME *ctx, MOVE_DIRECTION dir);

#endif //SOKOBAN_GAME_H
