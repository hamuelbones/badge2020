#ifdef __linux__
#include <stdio.h>
#include <sys/time.h> /* for gettimeofday */
#include <string.h> /* for memset */

#include "../linux/linuxcompat.h"
#include "../linux/bline.h"
#include "trucksim.h"
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

#endif

#include "build_bug_on.h"

/* Program states.  Initial state is MYPROGRAM_INIT */
enum myprogram_state_t {
	MYPROGRAM_INIT,
	MYPROGRAM_RUN,
	MYPROGRAM_EXIT,
};

// const char* roast_msgs[] = {
//     "Go back to driving school",
//     "This sim is an actual representation on how you drive in the real world",
//     "My grandma drives better than you"
// };

// // TODO: display roast msg on the screen
// static void random_roast_msg() {
//     int max_range = sizeof(roast_msgs)/sizeof(roast_msgs[0]);
//     int random_roast = rand() % max_range;
//     // printf("%s\n",roast_msgs[random_roast]);
// }

static enum myprogram_state_t myprogram_state = MYPROGRAM_INIT;

static void myprogram_init(void)
{
	FbInit();
	FbClear();
	myprogram_state = MYPROGRAM_RUN;
}

static void check_buttons()
{
	if (BUTTON_PRESSED_AND_CONSUME) {
		/* Pressing the button exits the program. You probably want to change this. */
		myprogram_state = MYPROGRAM_EXIT;
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
	FbWriteLine("TRUCK SIMULATOR");
	FbSwapBuffers();
}

static void myprogram_run()
{
	check_buttons();
	draw_screen();
}

static void myprogram_exit()
{
	myprogram_state = MYPROGRAM_INIT; /* So that when we start again, we do not immediately exit */
	returnToMenus();
}

/* You will need to rename myprogram_cb() something else. */
int truck_sim_cb(void)
{
	switch (myprogram_state) {
	case MYPROGRAM_INIT:
		myprogram_init();
		break;
	case MYPROGRAM_RUN:
		myprogram_run();
		break;
	case MYPROGRAM_EXIT:
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
        start_gtk(&argc, &argv, truck_sim_cb, 30);
        return 0;
}
#endif
