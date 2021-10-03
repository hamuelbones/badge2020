// Generated level file by convert_levels.py

#include "levels.h"

static const SOKOBAN_COORDS level_0_boxes[6] = {
    [0] = {.x = 5, .y = 2},
    [1] = {.x = 7, .y = 3},
    [2] = {.x = 5, .y = 4},
    [3] = {.x = 8, .y = 4},
    [4] = {.x = 2, .y = 7},
    [5] = {.x = 5, .y = 7},
};

static const SOKOBAN_COORDS level_0_goals[6] = {
    [0] = {.x = 19, .y = 6},
    [1] = {.x = 20, .y = 6},
    [2] = {.x = 19, .y = 7},
    [3] = {.x = 20, .y = 7},
    [4] = {.x = 19, .y = 8},
    [5] = {.x = 20, .y = 8},
};

static const uint8_t level_0_map[33] = {
    0b00001111, 0b10000000, 0b00000000, 
    0b00001000, 0b10000000, 0b00000000, 
    0b00001000, 0b10000000, 0b00000000, 
    0b00111000, 0b11100000, 0b00000000, 
    0b00100000, 0b00100000, 0b00000000, 
    0b11101011, 0b10100000, 0b11111100, 
    0b10001011, 0b10111111, 0b10000100, 
    0b10000000, 0b00000000, 0b00000100, 
    0b11111011, 0b11010111, 0b10000100, 
    0b00001000, 0b00011100, 0b11111100, 
    0b00001111, 0b11110000, 0b00000000, 
    };

static const SOKOBAN_LEVEL level_0 = {
    .level_size = {.x = 22, .y = 11},
    .player_start = {.x = 12, .y = 8},
    .num_boxes = 6,
    .box_coords = level_0_boxes,
    .goal_coords = level_0_goals,
    .map = level_0_map,
};

static const SOKOBAN_COORDS level_1_boxes[10] = {
    [0] = {.x = 7, .y = 2},
    [1] = {.x = 10, .y = 2},
    [2] = {.x = 6, .y = 3},
    [3] = {.x = 10, .y = 5},
    [4] = {.x = 9, .y = 6},
    [5] = {.x = 11, .y = 6},
    [6] = {.x = 4, .y = 7},
    [7] = {.x = 7, .y = 7},
    [8] = {.x = 9, .y = 7},
    [9] = {.x = 11, .y = 7},
};

static const SOKOBAN_COORDS level_1_goals[10] = {
    [0] = {.x = 1, .y = 1},
    [1] = {.x = 2, .y = 1},
    [2] = {.x = 1, .y = 2},
    [3] = {.x = 2, .y = 2},
    [4] = {.x = 1, .y = 3},
    [5] = {.x = 2, .y = 3},
    [6] = {.x = 1, .y = 4},
    [7] = {.x = 2, .y = 4},
    [8] = {.x = 1, .y = 5},
    [9] = {.x = 2, .y = 5},
};

static const uint8_t level_1_map[20] = {
    0b11111111, 0b11110000, 
    0b10000100, 0b00011100, 
    0b10000100, 0b00000100, 
    0b10000101, 0b11100100, 
    0b10000000, 0b01100100, 
    0b10000101, 0b00001100, 
    0b11111101, 0b10000100, 
    0b00100000, 0b00000100, 
    0b00100001, 0b00000100, 
    0b00111111, 0b11111100, 
    };

static const SOKOBAN_LEVEL level_1 = {
    .level_size = {.x = 14, .y = 10},
    .player_start = {.x = 7, .y = 4},
    .num_boxes = 10,
    .box_coords = level_1_boxes,
    .goal_coords = level_1_goals,
    .map = level_1_map,
};

static const SOKOBAN_COORDS level_2_boxes[11] = {
    [0] = {.x = 10, .y = 2},
    [1] = {.x = 12, .y = 2},
    [2] = {.x = 10, .y = 3},
    [3] = {.x = 13, .y = 3},
    [4] = {.x = 10, .y = 4},
    [5] = {.x = 12, .y = 4},
    [6] = {.x = 10, .y = 5},
    [7] = {.x = 10, .y = 6},
    [8] = {.x = 13, .y = 6},
    [9] = {.x = 9, .y = 7},
    [10] = {.x = 12, .y = 7},
};

static const SOKOBAN_COORDS level_2_goals[11] = {
    [0] = {.x = 1, .y = 6},
    [1] = {.x = 2, .y = 6},
    [2] = {.x = 3, .y = 6},
    [3] = {.x = 4, .y = 6},
    [4] = {.x = 2, .y = 7},
    [5] = {.x = 3, .y = 7},
    [6] = {.x = 4, .y = 7},
    [7] = {.x = 1, .y = 8},
    [8] = {.x = 2, .y = 8},
    [9] = {.x = 3, .y = 8},
    [10] = {.x = 4, .y = 8},
};

static const uint8_t level_2_map[30] = {
    0b00000000, 0b11111111, 0b00000000, 
    0b00000000, 0b10000001, 0b00000000, 
    0b00000000, 0b10010011, 0b00000000, 
    0b00000000, 0b10000010, 0b00000000, 
    0b00000000, 0b11000010, 0b00000000, 
    0b11111111, 0b10001011, 0b10000000, 
    0b10000001, 0b10000000, 0b10000000, 
    0b11000000, 0b00000000, 0b10000000, 
    0b10000001, 0b11111111, 0b10000000, 
    0b11111111, 0b00000000, 0b00000000, 
    };

static const SOKOBAN_LEVEL level_2 = {
    .level_size = {.x = 17, .y = 10},
    .player_start = {.x = 14, .y = 1},
    .num_boxes = 11,
    .box_coords = level_2_boxes,
    .goal_coords = level_2_goals,
    .map = level_2_map,
};

static const SOKOBAN_COORDS level_3_boxes[20] = {
    [0] = {.x = 11, .y = 3},
    [1] = {.x = 13, .y = 3},
    [2] = {.x = 5, .y = 4},
    [3] = {.x = 6, .y = 4},
    [4] = {.x = 7, .y = 4},
    [5] = {.x = 9, .y = 4},
    [6] = {.x = 12, .y = 4},
    [7] = {.x = 6, .y = 5},
    [8] = {.x = 12, .y = 5},
    [9] = {.x = 5, .y = 6},
    [10] = {.x = 6, .y = 6},
    [11] = {.x = 9, .y = 6},
    [12] = {.x = 11, .y = 6},
    [13] = {.x = 13, .y = 6},
    [14] = {.x = 6, .y = 7},
    [15] = {.x = 5, .y = 9},
    [16] = {.x = 2, .y = 10},
    [17] = {.x = 3, .y = 10},
    [18] = {.x = 5, .y = 10},
    [19] = {.x = 6, .y = 10},
};

static const SOKOBAN_COORDS level_3_goals[20] = {
    [0] = {.x = 17, .y = 1},
    [1] = {.x = 18, .y = 1},
    [2] = {.x = 19, .y = 1},
    [3] = {.x = 20, .y = 1},
    [4] = {.x = 17, .y = 2},
    [5] = {.x = 18, .y = 2},
    [6] = {.x = 19, .y = 2},
    [7] = {.x = 20, .y = 2},
    [8] = {.x = 17, .y = 3},
    [9] = {.x = 18, .y = 3},
    [10] = {.x = 19, .y = 3},
    [11] = {.x = 20, .y = 3},
    [12] = {.x = 17, .y = 4},
    [13] = {.x = 18, .y = 4},
    [14] = {.x = 19, .y = 4},
    [15] = {.x = 20, .y = 4},
    [16] = {.x = 17, .y = 5},
    [17] = {.x = 18, .y = 5},
    [18] = {.x = 19, .y = 5},
    [19] = {.x = 20, .y = 5},
};

static const uint8_t level_3_map[39] = {
    0b00000000, 0b00000011, 0b11111100, 
    0b00000000, 0b00000010, 0b00000100, 
    0b00011111, 0b11111110, 0b00000100, 
    0b00010000, 0b10000000, 0b00000100, 
    0b00010000, 0b10000010, 0b00000100, 
    0b00010000, 0b00000010, 0b00000100, 
    0b00010000, 0b10000011, 0b11111100, 
    0b11110000, 0b10000010, 0b00000000, 
    0b10001011, 0b11111110, 0b00000000, 
    0b10000000, 0b11000000, 0b00000000, 
    0b10001000, 0b01000000, 0b00000000, 
    0b10001000, 0b11000000, 0b00000000, 
    0b11111111, 0b10000000, 0b00000000, 
    };

static const SOKOBAN_LEVEL level_3 = {
    .level_size = {.x = 22, .y = 13},
    .player_start = {.x = 8, .y = 10},
    .num_boxes = 20,
    .box_coords = level_3_boxes,
    .goal_coords = level_3_goals,
    .map = level_3_map,
};

static const SOKOBAN_COORDS level_4_boxes[12] = {
    [0] = {.x = 11, .y = 2},
    [1] = {.x = 14, .y = 3},
    [2] = {.x = 10, .y = 5},
    [3] = {.x = 13, .y = 5},
    [4] = {.x = 9, .y = 6},
    [5] = {.x = 11, .y = 6},
    [6] = {.x = 12, .y = 6},
    [7] = {.x = 9, .y = 7},
    [8] = {.x = 12, .y = 7},
    [9] = {.x = 11, .y = 8},
    [10] = {.x = 10, .y = 9},
    [11] = {.x = 12, .y = 9},
};

static const SOKOBAN_COORDS level_4_goals[12] = {
    [0] = {.x = 1, .y = 5},
    [1] = {.x = 2, .y = 5},
    [2] = {.x = 3, .y = 5},
    [3] = {.x = 4, .y = 5},
    [4] = {.x = 1, .y = 6},
    [5] = {.x = 2, .y = 6},
    [6] = {.x = 3, .y = 6},
    [7] = {.x = 4, .y = 6},
    [8] = {.x = 1, .y = 7},
    [9] = {.x = 2, .y = 7},
    [10] = {.x = 3, .y = 7},
    [11] = {.x = 4, .y = 7},
};

static const uint8_t level_4_map[39] = {
    0b00000000, 0b11111000, 0b00000000, 
    0b00000000, 0b10001111, 0b10000000, 
    0b00000000, 0b10101100, 0b10000000, 
    0b00000000, 0b10000000, 0b10000000, 
    0b11111111, 0b10111000, 0b10000000, 
    0b10000001, 0b10000011, 0b10000000, 
    0b10000000, 0b00000011, 0b00000000, 
    0b10000001, 0b10000001, 0b00000000, 
    0b11111111, 0b10000011, 0b00000000, 
    0b00000000, 0b10000001, 0b00000000, 
    0b00000000, 0b11101101, 0b00000000, 
    0b00000000, 0b00100001, 0b00000000, 
    0b00000000, 0b00111111, 0b00000000, 
    };

static const SOKOBAN_LEVEL level_4 = {
    .level_size = {.x = 17, .y = 13},
    .player_start = {.x = 14, .y = 7},
    .num_boxes = 12,
    .box_coords = level_4_boxes,
    .goal_coords = level_4_goals,
    .map = level_4_map,
};

static const SOKOBAN_COORDS level_5_boxes[10] = {
    [0] = {.x = 8, .y = 3},
    [1] = {.x = 9, .y = 3},
    [2] = {.x = 9, .y = 4},
    [3] = {.x = 9, .y = 5},
    [4] = {.x = 5, .y = 6},
    [5] = {.x = 8, .y = 6},
    [6] = {.x = 6, .y = 7},
    [7] = {.x = 9, .y = 7},
    [8] = {.x = 5, .y = 8},
    [9] = {.x = 8, .y = 8},
};

static const SOKOBAN_COORDS level_5_goals[10] = {
    [0] = {.x = 1, .y = 1},
    [1] = {.x = 2, .y = 1},
    [2] = {.x = 1, .y = 2},
    [3] = {.x = 2, .y = 2},
    [4] = {.x = 1, .y = 3},
    [5] = {.x = 2, .y = 3},
    [6] = {.x = 1, .y = 4},
    [7] = {.x = 2, .y = 4},
    [8] = {.x = 1, .y = 5},
    [9] = {.x = 2, .y = 5},
};

static const uint8_t level_5_map[22] = {
    0b11111100, 0b11100000, 
    0b10000101, 0b10110000, 
    0b10000111, 0b00010000, 
    0b10000000, 0b00010000, 
    0b10000101, 0b00010000, 
    0b10011101, 0b00010000, 
    0b11110001, 0b00010000, 
    0b00010001, 0b00010000, 
    0b00010000, 0b00010000, 
    0b00010011, 0b00010000, 
    0b00011111, 0b11110000, 
    };

static const SOKOBAN_LEVEL level_5 = {
    .level_size = {.x = 12, .y = 11},
    .player_start = {.x = 9, .y = 1},
    .num_boxes = 10,
    .box_coords = level_5_boxes,
    .goal_coords = level_5_goals,
    .map = level_5_map,
};

static const SOKOBAN_COORDS level_6_boxes[11] = {
    [0] = {.x = 9, .y = 2},
    [1] = {.x = 10, .y = 2},
    [2] = {.x = 5, .y = 3},
    [3] = {.x = 3, .y = 4},
    [4] = {.x = 9, .y = 5},
    [5] = {.x = 2, .y = 6},
    [6] = {.x = 2, .y = 7},
    [7] = {.x = 4, .y = 7},
    [8] = {.x = 6, .y = 7},
    [9] = {.x = 2, .y = 9},
    [10] = {.x = 3, .y = 9},
};

static const SOKOBAN_COORDS level_6_goals[11] = {
    [0] = {.x = 9, .y = 6},
    [1] = {.x = 10, .y = 6},
    [2] = {.x = 8, .y = 7},
    [3] = {.x = 9, .y = 7},
    [4] = {.x = 10, .y = 7},
    [5] = {.x = 8, .y = 8},
    [6] = {.x = 9, .y = 8},
    [7] = {.x = 10, .y = 8},
    [8] = {.x = 8, .y = 9},
    [9] = {.x = 9, .y = 9},
    [10] = {.x = 10, .y = 9},
};

static const uint8_t level_6_map[24] = {
    0b00000001, 0b11110000, 
    0b01111111, 0b00011000, 
    0b11010011, 0b00001000, 
    0b10000000, 0b00001000, 
    0b10000011, 0b10001000, 
    0b11101111, 0b10111000, 
    0b10000111, 0b00010000, 
    0b10000000, 0b00010000, 
    0b10000111, 0b00010000, 
    0b10000101, 0b00010000, 
    0b10011101, 0b11110000, 
    0b11110000, 0b00000000, 
    };

static const SOKOBAN_LEVEL level_6 = {
    .level_size = {.x = 13, .y = 12},
    .player_start = {.x = 5, .y = 2},
    .num_boxes = 11,
    .box_coords = level_6_boxes,
    .goal_coords = level_6_goals,
    .map = level_6_map,
};

static const SOKOBAN_COORDS level_7_boxes[18] = {
    [0] = {.x = 7, .y = 2},
    [1] = {.x = 11, .y = 2},
    [2] = {.x = 13, .y = 2},
    [3] = {.x = 4, .y = 3},
    [4] = {.x = 7, .y = 3},
    [5] = {.x = 12, .y = 3},
    [6] = {.x = 5, .y = 4},
    [7] = {.x = 7, .y = 4},
    [8] = {.x = 4, .y = 5},
    [9] = {.x = 3, .y = 6},
    [10] = {.x = 5, .y = 6},
    [11] = {.x = 7, .y = 6},
    [12] = {.x = 5, .y = 7},
    [13] = {.x = 8, .y = 7},
    [14] = {.x = 4, .y = 8},
    [15] = {.x = 9, .y = 8},
    [16] = {.x = 11, .y = 8},
    [17] = {.x = 13, .y = 8},
};

static const SOKOBAN_COORDS level_7_goals[18] = {
    [0] = {.x = 3, .y = 13},
    [1] = {.x = 4, .y = 13},
    [2] = {.x = 5, .y = 13},
    [3] = {.x = 6, .y = 13},
    [4] = {.x = 7, .y = 13},
    [5] = {.x = 8, .y = 13},
    [6] = {.x = 3, .y = 14},
    [7] = {.x = 4, .y = 14},
    [8] = {.x = 5, .y = 14},
    [9] = {.x = 6, .y = 14},
    [10] = {.x = 7, .y = 14},
    [11] = {.x = 8, .y = 14},
    [12] = {.x = 3, .y = 15},
    [13] = {.x = 4, .y = 15},
    [14] = {.x = 5, .y = 15},
    [15] = {.x = 6, .y = 15},
    [16] = {.x = 7, .y = 15},
    [17] = {.x = 8, .y = 15},
};

static const uint8_t level_7_map[51] = {
    0b00111100, 0b00000000, 
    0b00000000, 0b00100111, 
    0b11111111, 0b00000000, 
    0b00100000, 0b00000001, 
    0b00000000, 0b00100100, 
    0b01000001, 0b00000000, 
    0b00100000, 0b00100001, 
    0b00000000, 0b11100101, 
    0b00111101, 0b00000000, 
    0b10100000, 0b00110001, 
    0b00000000, 0b10000001, 
    0b01000101, 0b00000000, 
    0b11000000, 0b00000001, 
    0b00000000, 0b01111001, 
    0b11111111, 0b00000000, 
    0b00111001, 0b11000000, 
    0b00000000, 0b00100000, 
    0b01000000, 0b00000000, 
    0b00100000, 0b01000000, 
    0b00000000, 0b00100000, 
    0b01000000, 0b00000000, 
    0b00100000, 0b01000000, 
    0b00000000, 0b00100000, 
    0b01000000, 0b00000000, 
    0b00111111, 0b11000000, 
    0b00000000, };

static const SOKOBAN_LEVEL level_7 = {
    .level_size = {.x = 16, .y = 17},
    .player_start = {.x = 1, .y = 6},
    .num_boxes = 18,
    .box_coords = level_7_boxes,
    .goal_coords = level_7_goals,
    .map = level_7_map,
};

static const SOKOBAN_COORDS level_8_boxes[15] = {
    [0] = {.x = 7, .y = 7},
    [1] = {.x = 8, .y = 7},
    [2] = {.x = 9, .y = 7},
    [3] = {.x = 8, .y = 8},
    [4] = {.x = 10, .y = 8},
    [5] = {.x = 6, .y = 9},
    [6] = {.x = 8, .y = 9},
    [7] = {.x = 3, .y = 10},
    [8] = {.x = 6, .y = 10},
    [9] = {.x = 11, .y = 10},
    [10] = {.x = 14, .y = 10},
    [11] = {.x = 7, .y = 11},
    [12] = {.x = 8, .y = 11},
    [13] = {.x = 10, .y = 11},
    [14] = {.x = 7, .y = 12},
};

static const SOKOBAN_COORDS level_8_goals[15] = {
    [0] = {.x = 13, .y = 1},
    [1] = {.x = 14, .y = 1},
    [2] = {.x = 15, .y = 1},
    [3] = {.x = 13, .y = 2},
    [4] = {.x = 14, .y = 2},
    [5] = {.x = 15, .y = 2},
    [6] = {.x = 13, .y = 3},
    [7] = {.x = 14, .y = 3},
    [8] = {.x = 15, .y = 3},
    [9] = {.x = 13, .y = 4},
    [10] = {.x = 14, .y = 4},
    [11] = {.x = 15, .y = 4},
    [12] = {.x = 13, .y = 5},
    [13] = {.x = 14, .y = 5},
    [14] = {.x = 15, .y = 5},
};

static const uint8_t level_8_map[54] = {
    0b00000000, 0b00111111, 0b10000000, 
    0b00000000, 0b00100000, 0b10000000, 
    0b00000011, 0b11100000, 0b10000000, 
    0b00000010, 0b00000000, 0b10000000, 
    0b00000010, 0b01100000, 0b10000000, 
    0b00000011, 0b01100000, 0b10000000, 
    0b00000111, 0b01111111, 0b10000000, 
    0b00000100, 0b00011000, 0b00000000, 
    0b01111100, 0b00001111, 0b10000000, 
    0b11000100, 0b00001000, 0b10000000, 
    0b10000000, 0b00000000, 0b10000000, 
    0b11111100, 0b00001111, 0b10000000, 
    0b00000100, 0b00001000, 0b00000000, 
    0b00000111, 0b10111000, 0b00000000, 
    0b00000000, 0b10010000, 0b00000000, 
    0b00000000, 0b10010000, 0b00000000, 
    0b00000000, 0b10010000, 0b00000000, 
    0b00000000, 0b11110000, 0b00000000, 
    };

static const SOKOBAN_LEVEL level_8 = {
    .level_size = {.x = 17, .y = 18},
    .player_start = {.x = 1, .y = 10},
    .num_boxes = 15,
    .box_coords = level_8_boxes,
    .goal_coords = level_8_goals,
    .map = level_8_map,
};

static const SOKOBAN_COORDS level_9_boxes[34] = {
    [0] = {.x = 10, .y = 5},
    [1] = {.x = 11, .y = 5},
    [2] = {.x = 12, .y = 5},
    [3] = {.x = 2, .y = 6},
    [4] = {.x = 3, .y = 6},
    [5] = {.x = 7, .y = 6},
    [6] = {.x = 8, .y = 6},
    [7] = {.x = 10, .y = 6},
    [8] = {.x = 3, .y = 7},
    [9] = {.x = 4, .y = 7},
    [10] = {.x = 5, .y = 7},
    [11] = {.x = 11, .y = 7},
    [12] = {.x = 2, .y = 8},
    [13] = {.x = 8, .y = 8},
    [14] = {.x = 9, .y = 8},
    [15] = {.x = 11, .y = 8},
    [16] = {.x = 12, .y = 8},
    [17] = {.x = 9, .y = 9},
    [18] = {.x = 8, .y = 10},
    [19] = {.x = 10, .y = 10},
    [20] = {.x = 12, .y = 10},
    [21] = {.x = 9, .y = 12},
    [22] = {.x = 11, .y = 12},
    [23] = {.x = 8, .y = 13},
    [24] = {.x = 9, .y = 13},
    [25] = {.x = 11, .y = 13},
    [26] = {.x = 13, .y = 13},
    [27] = {.x = 9, .y = 14},
    [28] = {.x = 8, .y = 15},
    [29] = {.x = 9, .y = 15},
    [30] = {.x = 10, .y = 15},
    [31] = {.x = 12, .y = 15},
    [32] = {.x = 13, .y = 15},
    [33] = {.x = 14, .y = 15},
};

static const SOKOBAN_COORDS level_9_goals[34] = {
    [0] = {.x = 15, .y = 6},
    [1] = {.x = 16, .y = 6},
    [2] = {.x = 17, .y = 6},
    [3] = {.x = 18, .y = 6},
    [4] = {.x = 15, .y = 7},
    [5] = {.x = 16, .y = 7},
    [6] = {.x = 17, .y = 7},
    [7] = {.x = 18, .y = 7},
    [8] = {.x = 19, .y = 7},
    [9] = {.x = 15, .y = 8},
    [10] = {.x = 16, .y = 8},
    [11] = {.x = 17, .y = 8},
    [12] = {.x = 18, .y = 8},
    [13] = {.x = 19, .y = 8},
    [14] = {.x = 15, .y = 9},
    [15] = {.x = 16, .y = 9},
    [16] = {.x = 17, .y = 9},
    [17] = {.x = 18, .y = 9},
    [18] = {.x = 19, .y = 9},
    [19] = {.x = 15, .y = 10},
    [20] = {.x = 16, .y = 10},
    [21] = {.x = 17, .y = 10},
    [22] = {.x = 18, .y = 10},
    [23] = {.x = 19, .y = 10},
    [24] = {.x = 15, .y = 11},
    [25] = {.x = 16, .y = 11},
    [26] = {.x = 17, .y = 11},
    [27] = {.x = 18, .y = 11},
    [28] = {.x = 19, .y = 11},
    [29] = {.x = 15, .y = 12},
    [30] = {.x = 16, .y = 12},
    [31] = {.x = 17, .y = 12},
    [32] = {.x = 18, .y = 12},
    [33] = {.x = 19, .y = 12},
};

static const uint8_t level_9_map[60] = {
    0b00000000, 0b00000011, 0b11000000, 
    0b00000000, 0b01111110, 0b01000000, 
    0b00000000, 0b01000000, 0b01000000, 
    0b00000000, 0b01001111, 0b01110000, 
    0b01110011, 0b11101110, 0b00010000, 
    0b11011110, 0b00000010, 0b00010000, 
    0b10000000, 0b00000010, 0b00011000, 
    0b10000010, 0b00000010, 0b00001000, 
    0b10000010, 0b00000010, 0b00001000, 
    0b11100010, 0b00000010, 0b00001000, 
    0b00100010, 0b00000010, 0b00001000, 
    0b00101111, 0b11101110, 0b00001000, 
    0b00100010, 0b00000010, 0b00001000, 
    0b00111010, 0b00000011, 0b11111000, 
    0b00001010, 0b00000000, 0b10000000, 
    0b00001010, 0b00000000, 0b10000000, 
    0b00001010, 0b00000010, 0b10000000, 
    0b00001011, 0b11111110, 0b10000000, 
    0b00001000, 0b00000000, 0b10000000, 
    0b00001111, 0b11111111, 0b10000000, 
    };

static const SOKOBAN_LEVEL level_9 = {
    .level_size = {.x = 21, .y = 20},
    .player_start = {.x = 2, .y = 5},
    .num_boxes = 34,
    .box_coords = level_9_boxes,
    .goal_coords = level_9_goals,
    .map = level_9_map,
};

static const SOKOBAN_LEVEL *levels[10] = {
    [0] = &level_0,
    [1] = &level_1,
    [2] = &level_2,
    [3] = &level_3,
    [4] = &level_4,
    [5] = &level_5,
    [6] = &level_6,
    [7] = &level_7,
    [8] = &level_8,
    [9] = &level_9,
};

uint8_t soko_level_count(void) {
    return 10;
}

const SOKOBAN_LEVEL * soko_get_level(uint8_t num) {
    return levels[num];
}

