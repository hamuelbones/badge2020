/*********************************************

 Smashout game (like breakout) for HackRVA 2020 badge

 Author: Stephen M. Cameron <stephenmcameron@gmail.com>
 (c) 2019 Stephen M. Cameron

**********************************************/
#ifdef __linux__
#include <stdio.h>
#include <sys/time.h> /* for gettimeofday */
#include <string.h> /* for memset */

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

#endif

#include "build_bug_on.h"
#include "xorshift.h"
#include "achievements.h"

/* TODO figure out where these should really come from */
#define SCREEN_XDIM 132
#define SCREEN_YDIM 132
#define PADDLE_HEIGHT 15
#define PADDLE_WIDTH 20
#define PADDLE_SPEED 10
#define BALL_STARTX (SCREEN_XDIM / 2)
#define BALL_STARTY (SCREEN_YDIM / 2)
#define BALL_START_VX 3
#define BALL_START_VY 2

static struct smashout_paddle {
	int x, y, w;
} paddle, old_paddle;

static struct smashout_ball {
	int x, y, vx, vy;
} ball, oldball;

/* Program states.  Initial state is SMASHOUT_GAME_INIT */
enum smashout_program_state_t {
	SMASHOUT_GAME_INIT,
	SMASHOUT_GAME_PLAY,
	SMASHOUT_GAME_EXIT,
};

static enum smashout_program_state_t smashout_program_state = SMASHOUT_GAME_INIT;

static void smashout_game_init(void)
{
	FbInit();
	FbClear();
	paddle.x = SCREEN_XDIM / 2;
	paddle.y = SCREEN_YDIM - PADDLE_HEIGHT;
	paddle.w = PADDLE_WIDTH;
	old_paddle = paddle;
	ball.x = BALL_STARTX;
	ball.y = BALL_STARTY;
	ball.vx = BALL_START_VX;
	ball.vy = BALL_START_VY;
	oldball = ball;
	smashout_program_state = SMASHOUT_GAME_PLAY;
}

static void smashout_check_buttons()
{
	if (LEFT_BTN_AND_CONSUME) {
		paddle.x = paddle.x - PADDLE_SPEED;
		if (paddle.x < paddle.w / 2)
			paddle.x = paddle.w / 2;
	} else if (RIGHT_BTN_AND_CONSUME) {
		paddle.x = paddle.x + PADDLE_SPEED;
		if (paddle.x > SCREEN_XDIM - paddle.w / 2)
			paddle.x = SCREEN_XDIM - paddle.w / 2;
	}
}

static void smashout_draw_paddle()
{
	int dx = old_paddle.w / 2;
	FbColor(BLACK);
	FbHorizontalLine(old_paddle.x - dx, old_paddle.y, old_paddle.x + dx, old_paddle.y);
	FbColor(WHITE);
	FbHorizontalLine(paddle.x - dx, paddle.y, paddle.x + dx, paddle.y);
	old_paddle = paddle;
}

static void smashout_draw_ball()
{
	FbColor(BLACK);
	FbHorizontalLine(oldball.x - 1, oldball.y - 1, oldball.x + 1, oldball.y - 1);
	FbHorizontalLine(oldball.x - 1, oldball.y + 1, oldball.x + 1, oldball.y + 1);
	FbVerticalLine(oldball.x - 1, oldball.y - 1, oldball.x - 1, oldball.y + 1);
	FbVerticalLine(oldball.x + 1, oldball.y - 1, oldball.x + 1, oldball.y + 1);
	FbColor(WHITE);
	FbHorizontalLine(ball.x - 1, ball.y - 1, ball.x + 1, ball.y - 1);
	FbHorizontalLine(ball.x - 1, ball.y + 1, ball.x + 1, ball.y + 1);
	FbVerticalLine(ball.x - 1, ball.y - 1, ball.x - 1, ball.y + 1);
	FbVerticalLine(ball.x + 1, ball.y - 1, ball.x + 1, ball.y + 1);
}

static void smashout_move_ball()
{
	oldball = ball;
	ball.x = ball.x + ball.vx;
	ball.y = ball.y + ball.vy;
	if (ball.x > SCREEN_XDIM - 2) {
		ball.x = SCREEN_XDIM - 2;
		if (ball.vx > 0)
			ball.vx = -ball.vx;
	}
	if (ball.y > SCREEN_YDIM - 2) {
		ball.y = SCREEN_YDIM - 2;
		if (ball.vy > 0)
			ball.vy = -ball.vy;
	}
	if (ball.x < 1) {
		ball.x = 1;
		if (ball.vx < 0)
			ball.vx = -ball.vx;
	}
	if (ball.y < 1) {
		ball.y = 1;
		if (ball.vy < 0)
			ball.vy = -ball.vy;
	}
}

static void smashout_draw_screen()
{
	smashout_draw_paddle();
	smashout_draw_ball();
	FbSwapBuffers();
}

static void smashout_game_play()
{
	smashout_check_buttons();
	smashout_move_ball();
	smashout_draw_screen();
}

static void smashout_game_exit()
{
}

int smashout_cb(void)
{
	switch (smashout_program_state) {
	case SMASHOUT_GAME_INIT:
		smashout_game_init();
		break;
	case SMASHOUT_GAME_PLAY:
		smashout_game_play();
		break;
	case SMASHOUT_GAME_EXIT:
		smashout_game_exit();
		break;
	default:
		break;
	}
	return 0;
}

#ifdef __linux__
int main(int argc, char *argv[])
{
        start_gtk(&argc, &argv, smashout_cb, 30);
        return 0;
}
#endif
