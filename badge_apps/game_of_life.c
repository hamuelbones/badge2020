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

static enum gameoflife_state_t gameoflife_state = GAMEOFLIFE_INIT;

static void render_grid(){
	int n;
	for (n = 0; n < GRID_SIZE; n++){
		#ifdef __linux__
			// printf("random 1 or 0: %d\n", xorshift((unsigned int *)&timestamp) % 2);
			printf("%d", game_grid.grid_cells[n].alive);

			/* split into rows */
			if((n + 1) % ROW_SIZE(GRID_SIZE) == 0){
				printf("\n");
			}
			
		#endif
	}

	#ifdef __linux__
		printf("\n"); /* just separating with a newline for now*/
	#endif
}

static void init_grid(){
	int n;

	for (n = 0; n < GRID_SIZE; n++){
		game_grid.grid_cells[n].alive = xorshift((unsigned int *)&timestamp) % 2;
	}
}

static void myprogram_init(void)
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

static void myprogram_run()
{
	check_buttons();
	draw_screen();
}

static void myprogram_exit()
{
	gameoflife_state = GAMEOFLIFE_INIT; /* So that when we start again, we do not immediately exit */
	returnToMenus();
}

/* You will need to rename myprogram_cb() something else. */
int game_of_life_cb(void)
{
	switch (gameoflife_state) {
	case GAMEOFLIFE_INIT:
		myprogram_init();
		break;
	case GAMEOFLIFE_RUN:
		myprogram_run();
		break;
	case GAMEOFLIFE_EXIT:
		myprogram_exit();
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
