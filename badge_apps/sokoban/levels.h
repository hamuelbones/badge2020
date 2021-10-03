//
// Created by Samuel Jones on 9/29/21.
//

#ifndef SOKOBAN_LEVELS_H
#define SOKOBAN_LEVELS_H

#include "types.h"

// Get the number of levels game has.
uint8_t soko_level_count(void);

// Get a level definition.
const SOKOBAN_LEVEL * soko_get_level(uint8_t num);

#endif //SOKOBAN_LEVELS_H
