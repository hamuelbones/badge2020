//
// Created by Samuel Jones on 10/1/21.
//

#include "tile.h"
#ifdef __linux__
#include "linuxcompat.h"
#else
#include "fb.h"
#include "colors.h"
#endif

// 2 bit palette
static const uint8_t _soko_player_data[SOKO_TILESIZE_X*SOKO_TILESIZE_Y/4] = {
        P_2B(0, 0, 0, 2), P_2B(2, 0, 0, 0),
        P_2B(0, 1, 0, 2), P_2B(2, 2, 2, 0),
        P_2B(0, 1, 0, 1), P_2B(1, 0, 0, 0),
        P_2B(0, 0, 1, 1), P_2B(1, 1, 0, 0),
        P_2B(0, 0, 0, 1), P_2B(1, 0, 1, 0),
        P_2B(0, 0, 0, 1), P_2B(1, 0, 1, 0),
        P_2B(0, 0, 3, 3), P_2B(3, 3, 0, 0),
        P_2B(0, 3, 3, 0), P_2B(0, 3, 3, 0),
};

static uint16_t _soko_player_palette[4] = {
        SKIP_PIXEL,
        CYAN,
        RED,
        MAGENTA
};

const TILE _soko_player_tile = {
        .x = 8,
        .y = 8,
        .bits = 2,
        .data = _soko_player_data,
        .palette = _soko_player_palette,
};

// 2 bit palette
static const uint8_t _soko_wall_data[SOKO_TILESIZE_X*SOKO_TILESIZE_Y/4] = {

        P_2B(2, 1, 1, 1), P_2B(1, 1, 2, 2),
        P_2B(1, 0, 0, 1), P_2B(1, 0, 2, 2),
        P_2B(1, 0, 2, 2), P_2B(1, 0, 0, 1),
        P_2B(1, 1, 2, 2), P_2B(2, 1, 1, 1),
        P_2B(1, 1, 1, 2), P_2B(2, 2, 1, 1),
        P_2B(1, 0, 0, 1), P_2B(2, 2, 0, 1),
        P_2B(2, 2, 0, 1), P_2B(1, 0, 0, 1),
        P_2B(2, 2, 1, 1), P_2B(1, 1, 1, 2),
};

static uint16_t _soko_wall_palette[4] = {
        SKIP_PIXEL,
        BLUE,
        GREEN,
        CYAN,
};

const TILE _soko_wall_tile = {
        .x = 8,
        .y = 8,
        .bits = 2,
        .data = _soko_wall_data,
        .palette = _soko_wall_palette,
};

// 2 bit palette
static const uint8_t _soko_box_data[SOKO_TILESIZE_X*SOKO_TILESIZE_Y/4] = {
        P_2B(1, 1, 1, 1), P_2B(1, 1, 1, 1),
        P_2B(1, 2, 0, 0), P_2B(0, 0, 2, 1),
        P_2B(1, 0, 2, 0), P_2B(0, 2, 0, 1),
        P_2B(1, 0, 0, 1), P_2B(1, 0, 0, 1),
        P_2B(1, 0, 0, 1), P_2B(1, 0, 0, 1),
        P_2B(1, 0, 2, 0), P_2B(0, 2, 0, 1),
        P_2B(1, 2, 0, 0), P_2B(0, 0, 2, 1),
        P_2B(1, 1, 1, 1), P_2B(1, 1, 1, 1),
};

static uint16_t _soko_box_palette[4] = {
        SKIP_PIXEL,
        YELLOW,
        GREEN,
        MAGENTA
};

const TILE _soko_box_tile = {
        .x = 8,
        .y = 8,
        .bits = 2,
        .data = _soko_box_data,
        .palette = _soko_box_palette,
};


// 2 bit palette
static const uint8_t _soko_goal_data[SOKO_TILESIZE_X*SOKO_TILESIZE_Y/4] = {
        P_2B(0, 0, 0, 0), P_2B(0, 0, 0, 0),
        P_2B(0, 0, 1, 1), P_2B(1, 1, 0, 0),
        P_2B(0, 1, 1, 2), P_2B(2, 1, 1, 0),
        P_2B(0, 1, 2, 2), P_2B(2, 2, 1, 0),
        P_2B(0, 1, 2, 2), P_2B(2, 2, 1, 0),
        P_2B(0, 1, 1, 2), P_2B(2, 1, 1, 0),
        P_2B(0, 0, 1, 1), P_2B(1, 1, 0, 0),
        P_2B(0, 0, 0, 0), P_2B(0, 0, 0, 0),
};

static uint16_t _soko_goal_palette[4] = {
        SKIP_PIXEL,
        WHITE,
        CYAN,
        MAGENTA
};

const TILE _soko_goal_tile = {
        .x = 8,
        .y = 8,
        .bits = 2,
        .data = _soko_goal_data,
        .palette = _soko_goal_palette,
};


static const TILE* _tiles[TILE_MAX] = {
        &_soko_player_tile,
        &_soko_wall_tile,
        &_soko_goal_tile,
        &_soko_box_tile,
};

const TILE* soko_tile_get(TILE_ID id) {
    return _tiles[id];
}
