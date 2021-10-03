//
// Created by Samuel Jones on 10/1/21.
//

#ifndef SOKOBAN_TILE_H
#define SOKOBAN_TILE_H

#include "types.h"

typedef enum {
    TILE_PLAYER,
    TILE_WALL,
    TILE_GOAL,
    TILE_BOX,
    TILE_MAX
} TILE_ID;

#define SKIP_PIXEL 0b1010101010101010
#define P_2B(a, b, c, d)  ((uint8_t)((a) | (b << 2) | (c << 4) | (d << 6)))

typedef struct {
    uint8_t x;
    uint8_t y;
    const uint8_t * data;
    const uint16_t * palette;
    uint8_t bits;
} TILE;

const TILE* soko_tile_get(TILE_ID id);


#endif //SOKOBAN_TILE_H
