


#ifndef SOKOBAN_TYPES_H
#define SOKOBAN_TYPES_H

#include <stdint.h>

#define SOKO_TILES_X 15
#define SOKO_TILES_Y 15

#define SOKO_TILESIZE_X 8
#define SOKO_TILESIZE_Y 8

#define SOKO_PADDING_X 6
#define SOKO_PADDING_Y 2

typedef struct {
    int16_t x;
    int16_t y;
} SOKOBAN_COORDS;

typedef struct {
    SOKOBAN_COORDS level_size;
    SOKOBAN_COORDS player_start;
    const SOKOBAN_COORDS * box_coords;
    const SOKOBAN_COORDS * goal_coords;
    const uint8_t *map;
    uint8_t num_boxes;
} SOKOBAN_LEVEL;

typedef struct {
    uint16_t moves;
    uint16_t pushes;
    SOKOBAN_COORDS player_location;
    SOKOBAN_COORDS level_focus;
    SOKOBAN_COORDS box_locations[34];
    const SOKOBAN_LEVEL *level;
    uint8_t level_index;
} SOKOBAN_GAME;


typedef enum {
    MOVE_UP,
    MOVE_DOWN,
    MOVE_LEFT,
    MOVE_RIGHT
} MOVE_DIRECTION;

#endif //SOKOBAN_TYPES_H
