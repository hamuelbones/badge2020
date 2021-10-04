//
// Created by Samuel Jones on 9/27/21.
//

// Sokoban, for the badge. The original block-pushing puzzle game.

#include <string.h>
#include <stdio.h>
#ifdef __linux__
#include <sys/time.h> /* for gettimeofday */
#include <stdint.h>
#include <stdbool.h>

#include "../linux/linuxcompat.h"
#include "../linux/bline.h"
#else
#include "colors.h"
#include "menu.h"
#include "buttons.h"
#include "fb.h"
#endif

#include "sokoban/types.h"
#include "sokoban/game.h"
#include "sokoban/levels.h"
#include "sokoban/draw.h"

#include "build_bug_on.h"

/* Program states.  Initial state is SOKOBAN_INIT */
enum sokoban_state_t {
    SOKOBAN_INIT,
    SOKOBAN_MAIN_MENU,
    SOKOBAN_LEVEL_SELECT_MENU,
    SOKOBAN_PLAY,
    SOKOBAN_PLAY_MENU,
    SOKOBAN_WIN_LEVEL,
    SOKOBAN_EXIT,
};


static SOKOBAN_GAME _sokoban;
static enum sokoban_state_t sokoban_state = SOKOBAN_INIT;
int8_t menuIndex;

static void sokoban_init(void)
{
    FbInit();
    FbClear();
    sokoban_state = SOKOBAN_MAIN_MENU;
}


static void sokoban_main_menu() {

    if (BUTTON_PRESSED_AND_CONSUME) {
        if (menuIndex == 0) {
            // New Game
            _sokoban.level_index = 0;
            soko_game_load_level(&_sokoban, soko_get_level(_sokoban.level_index));
            sokoban_state = SOKOBAN_PLAY;
        } else if (menuIndex == 1) {
            // Level Select
            sokoban_state = SOKOBAN_LEVEL_SELECT_MENU;
        } else if (menuIndex == 2) {
            // Exit
            sokoban_state = SOKOBAN_EXIT;
        }
    }

    if (DOWN_BTN_AND_CONSUME) {
        menuIndex++;
        if (menuIndex > 2) {
            menuIndex = 2;
        }
    }

    if (UP_BTN_AND_CONSUME) {
        menuIndex--;
        if (menuIndex < 0) {
            menuIndex = 0;
        }
    }

    if (sokoban_state == SOKOBAN_MAIN_MENU) {
        FbClear();
        FbMove(10, 5);
        FbColor(WHITE);
        FbWriteLine("New Game");
        FbMove(10, 5 + 8);
        FbWriteLine("Level Select");
        FbMove(10, 5 + 16);
        FbWriteLine("Exit");

        FbMove(0, 5 + menuIndex * 8);
        FbWriteLine("-");
        FbSwapBuffers();
    } else {
        menuIndex = 0;
    }
}


static void sokoban_level_select_menu() {

    if (BUTTON_PRESSED_AND_CONSUME) {
        soko_game_load_level(&_sokoban, soko_get_level(_sokoban.level_index));
        sokoban_state = SOKOBAN_PLAY;
    }


    if (UP_BTN_AND_CONSUME) {
        if (_sokoban.level_index != soko_level_count()-1) {
            _sokoban.level_index++;
        }
    }

    if (DOWN_BTN_AND_CONSUME) {
        if (_sokoban.level_index != 0) {
            _sokoban.level_index--;
        }
    }

    if (sokoban_state == SOKOBAN_LEVEL_SELECT_MENU) {
        FbClear();
        FbMove(10,5);
        FbColor(WHITE);
        char text[20] = "Level: ";
        itoa(text+7, _sokoban.level_index+1, 10);
        FbWriteLine(text);
        FbSwapBuffers();
    }
}


static void check_buttons_and_move_game()
{
    bool pressed = false;
    MOVE_DIRECTION direction = MOVE_UP;

    if (BUTTON_PRESSED_AND_CONSUME) {
        sokoban_state = SOKOBAN_PLAY_MENU;
        menuIndex = 0;
    } else if (LEFT_BTN_AND_CONSUME) {
        pressed = true;
        direction = MOVE_LEFT;
    } else if (RIGHT_BTN_AND_CONSUME) {
        pressed = true;
        direction = MOVE_RIGHT;
    } else if (UP_BTN_AND_CONSUME) {
        pressed = true;
        direction = MOVE_UP;
    } else if (DOWN_BTN_AND_CONSUME) {
        pressed = true;
        direction = MOVE_DOWN;
    }

    if (pressed) {
        soko_game_move(&_sokoban, direction);
    }
}


static void sokoban_play()
{
    check_buttons_and_move_game();
    soko_draw_game(&_sokoban);
    bool solved = soko_is_solved(&_sokoban);
    if (solved) {
        sokoban_state = SOKOBAN_WIN_LEVEL;
    }
}


static void sokoban_play_menu() {

    if (BUTTON_PRESSED_AND_CONSUME) {
        if (menuIndex == 0) {
            // Resume
            sokoban_state = SOKOBAN_PLAY;
        } else if (menuIndex == 1) {
            // Restart
            soko_game_load_level(&_sokoban, soko_get_level(_sokoban.level_index));
            sokoban_state = SOKOBAN_PLAY;
        } else if (menuIndex == 2) {
            // Back to main
            sokoban_state = SOKOBAN_MAIN_MENU;
        } else if (menuIndex == 3) {
            // Exit
            sokoban_state = SOKOBAN_EXIT;
        }
    }

    if (DOWN_BTN_AND_CONSUME) {
        menuIndex++;
        if (menuIndex > 3) {
            menuIndex = 3;
        }
    }

    if (UP_BTN_AND_CONSUME) {
        menuIndex--;
        if (menuIndex < 0) {
            menuIndex = 0;
        }
    }

    if (sokoban_state == SOKOBAN_PLAY_MENU) {
        FbClear();
        FbMove(10,5);
        FbColor(WHITE);
        FbWriteLine("Resume");
        FbMove(10,5+8);
        FbWriteLine("Restart Level");
        FbMove(10,5+16);
        FbWriteLine("Main Menu");
        FbMove(10,5+24);
        FbWriteLine("Exit");

        FbMove(0, 5+menuIndex*8);
        FbWriteLine("-");
        FbSwapBuffers();
    } else {
        menuIndex = 0;
    }
}


static void sokoban_win_level() {
    if (BUTTON_PRESSED_AND_CONSUME) {
        _sokoban.level_index++;
        if (_sokoban.level_index == soko_level_count()) {
            sokoban_state = SOKOBAN_EXIT;
        } else {
            soko_game_load_level(&_sokoban, soko_get_level(_sokoban.level_index));
            sokoban_state = SOKOBAN_PLAY;
        }
    }

    if (sokoban_state == SOKOBAN_WIN_LEVEL) {
        FbClear();
        FbMove(10,5);
        FbColor(WHITE);
        char text[20] = "Lv ";

        FbMove(10,5+8);
        itoa(text+3, _sokoban.level_index+1, 10);
        strcat(text, " Clear!");
        FbWriteLine(text);

        FbMove(10,5+16);
        text[0] = '\0';
        strcat(text, "Moves: ");
        itoa(text+7, _sokoban.moves, 10);
        FbWriteLine(text);

        FbMove(10,5+24);
        text[0] = '\0';
        strcat(text, "Pushes: ");
        itoa(text+8, _sokoban.pushes, 10);
        FbWriteLine(text);

        FbMove(10,5+32);
        if (_sokoban.level_index == soko_level_count()-1) {
            FbWriteLine("You Won! Press to exit.");
        } else {
            FbWriteLine("Press for next level.");
        }
        FbSwapBuffers();
    }
}

static void sokoban_exit()
{
    sokoban_state = SOKOBAN_INIT; /* So that when we start again, we do not immediately exit */
    returnToMenus();
}

/* You will need to rename sokoban_cb() something else. */
int sokoban_cb(void)
{
    switch (sokoban_state) {
        case SOKOBAN_INIT:
            sokoban_init();
            break;
        case SOKOBAN_MAIN_MENU:
            sokoban_main_menu();
            break;
        case SOKOBAN_LEVEL_SELECT_MENU:
            sokoban_level_select_menu();
            break;
        case SOKOBAN_PLAY:
            sokoban_play();
            break;
        case SOKOBAN_PLAY_MENU:
            sokoban_play_menu();
            break;
        case SOKOBAN_WIN_LEVEL:
            sokoban_win_level();
            break;
        case SOKOBAN_EXIT:
            sokoban_exit();
            break;
        default:
            break;
    }
    return 0;
}

#ifdef __linux__
int main(int argc, char *argv[])
{
        start_gtk(&argc, &argv, sokoban_cb, 30);
        return 0;
}
#endif
