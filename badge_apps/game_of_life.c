#ifdef __linux__
#include <stdio.h>
#include <sys/time.h> /* for gettimeofday */
#include <string.h> /* for memset */
#include <math.h>
#include "game_of_life.h"

#include "../linux/linuxcompat.h"
#include "../linux/bline.h"
#else
#include "colors.h"
#include "menu.h"
#include "buttons.h"

/* TODO: I shouldn't have to declare these myself. */
#define size_t int
extern char *strcpy(char *dest, const char *src);
extern char *strncpy(char *dest, const char *src, size_t n);
extern void *memset(void *s, int c, size_t n);
extern char *strcat(char *dest, const char *src);

extern int timestamp;

#endif

#include "build_bug_on.h"
#include "./xorshift.h"

/* GRID_SIZE must be a square number */
#define GRID_SIZE 256
#define CELL_SIZE 2
#define ROW_SIZE(x) ((int)(sqrt((x))))

static struct Grid {
	struct Cell {
		unsigned char alive;
		unsigned int neighbor_count;
		struct coordinates {
			unsigned int x;
			unsigned int y;
		} cell_coordinates;
	} grid_cells[GRID_SIZE];
} game_grid;

/* Program states.  Initial state is GAMEOFLIFE_INIT */
enum gameoflife_state_t {
	GAMEOFLIFE_INIT,
	GAMEOFLIFE_RUN,
	GAMEOFLIFE_EXIT,
};

unsigned int next_gen[GRID_SIZE];

static enum gameoflife_state_t gameoflife_state = GAMEOFLIFE_INIT;

static void next_generation(unsigned int alive_count, unsigned int cell, int current_index){
    if(cell == 1)
    {
        if(alive_count == 2 || alive_count == 3) {
            next_gen[current_index] = 1;
        } else {
            next_gen[current_index] = 0;
        }
    } else {
        if(alive_count == 3) {// only way a dead cell can be revived if it has exactly 3 alives neighbors
            next_gen[current_index] = 1;
        } else {
            next_gen[current_index] = 0;
        }
    }
}

static int range(int num) {
    if(num >= 0 && num < GRID_SIZE){
        return 2;
    } else {
        return -1;
    }
}

static void render_grid(){
	int n;
	unsigned int alive_count = 0;
	for (n = 0; n < GRID_SIZE; n++){
		#ifdef __linux__
			// printf("random 1 or 0: %d\n", xorshift((unsigned int *)&timestamp) % 2);
			// printf("X%d ", game_grid.grid_cells[n].cell_coordinates.x);
			// printf("Y%d ", game_grid.grid_cells[n].cell_coordinates.y);
			// printf("%d", game_grid.grid_cells[n].alive);

			// lEFT neighbor
			if(range(n - 1) == 2) {
				if(n % ROW_SIZE(GRID_SIZE) != 0){// LEFT OUT OF BOUND cond
					if(game_grid.grid_cells[n - 1].alive == 1) {
						alive_count ++;
					}
				}
			}

			// RIGHT neighbor
			if(range(n + 1) == 2) {
				if((n+1) % ROW_SIZE(GRID_SIZE) != 0){// RIGHT OUT OF BOUND cond
					if(game_grid.grid_cells[n + 1].alive == 1) {
						alive_count ++;
					}
				}
			}

    		// TOP neighbor
			if(range(n - ROW_SIZE(GRID_SIZE)) == 2) {
				if(game_grid.grid_cells[n - ROW_SIZE(GRID_SIZE)].alive == 1) {
					alive_count ++;
				}  
			}

			// BOTTOM neighbor
			if(range(n + ROW_SIZE(GRID_SIZE)) == 2) {
				if(game_grid.grid_cells[n + ROW_SIZE(GRID_SIZE)].alive == 1) {
					alive_count++;
				}
			}

			// TOP RIGHT neighbor
			if(range(n - (ROW_SIZE(GRID_SIZE) - 1)) == 2) {
				if((n+1) % ROW_SIZE(GRID_SIZE) != 0){
					if(game_grid.grid_cells[n - (ROW_SIZE(GRID_SIZE)-1)].alive == 1) {
						alive_count++;
					}
				}
			}

			// TOP LEFT neighbor
			if(range(n - (ROW_SIZE(GRID_SIZE) + 1)) == 2) {
				if(n % ROW_SIZE(GRID_SIZE) != 0) {
					if(game_grid.grid_cells[n - (ROW_SIZE(GRID_SIZE) + 1)].alive == 1) {
						alive_count++;
					}
				}
			}

			// BOTTOM LEFT neighbor
			if(range(n + (ROW_SIZE(GRID_SIZE) - 1)) == 2) {
				if(n % ROW_SIZE(GRID_SIZE) != 0){
					if(game_grid.grid_cells[n + (ROW_SIZE(GRID_SIZE) - 1)].alive == 1) {
						alive_count++;
					}   
				}
			}

			// BOTTOM RIGHT
			if(range(n + (ROW_SIZE(GRID_SIZE) + 1)) == 2) {
				if((n+1) % ROW_SIZE(GRID_SIZE) != 0) {
					if(game_grid.grid_cells[n + (ROW_SIZE(GRID_SIZE) + 1)].alive == 1) {
						alive_count++;
					}   
				}
			}

			/* split into rows */
			if((n + 1) % ROW_SIZE(GRID_SIZE) == 0){
				printf("\n");
			}

			next_generation(alive_count, game_grid.grid_cells[n].alive, n);

			alive_count = 0;
			
		#endif
	}
	// this is used to display the next generation for testing purposes. 
	// for(int i = 0; i<GRID_SIZE; i++) {
	// 	printf("%d", next_gen[i]);

	// 	if((i + 1) % ROW_SIZE(GRID_SIZE) == 0){
	// 		printf("\n");
	// 	}
	// }

	#ifdef __linux__
		printf("\n"); /* just separating with a newline for now*/
	#endif
}

static void init_grid(){
	int n;

	// X Y coordinates
	unsigned int x = 0;
	unsigned int y = 0;

	for (n = 0; n < GRID_SIZE; n++){
		game_grid.grid_cells[n].alive = xorshift((unsigned int *)&timestamp) % 2;
		
		if((n+1) % ROW_SIZE(GRID_SIZE) != 0){
			game_grid.grid_cells[n].cell_coordinates.x = x;
			game_grid.grid_cells[n].cell_coordinates.y = y;
			y++;
		}

		if((n+1) % ROW_SIZE(GRID_SIZE) == 0){
			game_grid.grid_cells[n].cell_coordinates.x = x;
			game_grid.grid_cells[n].cell_coordinates.y = y;
			x++;
			y = 0;
		}

	}
}

static void game_of_life_init(void)
{
	#ifdef __linux__
		printf("grid size %d\nrow size: %d\n\n", GRID_SIZE, ROW_SIZE(GRID_SIZE));
	#endif
	FbInit();
	FbClear();
	gameoflife_state = GAMEOFLIFE_RUN;
}


static void check_buttons()
{

	if (BUTTON_PRESSED_AND_CONSUME) {
		init_grid();
		render_grid();
	} else if (LEFT_BTN_AND_CONSUME) {
	} else if (RIGHT_BTN_AND_CONSUME) {
	} else if (UP_BTN_AND_CONSUME) {
	} else if (DOWN_BTN_AND_CONSUME) {
	}
}

static void draw_screen()
{
	FbColor(WHITE);
	FbMove(10, SCREEN_YDIM / 2);
	FbWriteLine("GAME OF LIFE");
	FbSwapBuffers();
}

static void game_of_life_run()
{
	check_buttons();
	draw_screen();
}

static void game_of_life_exit()
{
	gameoflife_state = GAMEOFLIFE_INIT; /* So that when we start again, we do not immediately exit */
	returnToMenus();
}

int game_of_life_cb(void)
{
	switch (gameoflife_state) {
	case GAMEOFLIFE_INIT:
		game_of_life_init();
		break;
	case GAMEOFLIFE_RUN:
		game_of_life_run();
		break;
	case GAMEOFLIFE_EXIT:
		game_of_life_exit();
		break;
	default:
		break;
	}
	return 0;
}

#ifdef __linux__
int main(int argc, char *argv[])
{
        start_gtk(&argc, &argv, game_of_life_cb, 30);
        return 0;
}
#endif
