#include <vector>
#include <cstdlib>
#include <ctime>
#include "terminal.h"

enum Direction
{
	UP,
	DOWN,
};

struct Vec2D
{
	int x;
	int y;
};

void draw_border()
{
	/*Draw a border for the playing field.*/
	for (int x = 0; x < term::width(); ++x) {
		term::set_cell(x, 0, 'x');
	}
	for (int x = 0; x < term::height(); ++x) {
		term::set_cell(0, x, 'x');
	}
	for (int x = 0; x < term::height(); ++x) {
		term::set_cell(term::width()-1, x, 'x');
	}
	for (int x = 0; x < term::width(); ++x) {
		term::set_cell(x, term::height()-1, 'x');
	}
}

void draw_ball(Vec2D ball)
{
	/*Sets the ball on the field.
		@param ball contains the current x and y coordinate of the ball*/
	term::set_cell(ball.x, ball.y, 'o');
}

void draw_paddle(std::vector<Vec2D>& paddle)
{
	/*Sets the paddle on the field.
		@param paddle is a vector that contains the current x and y coordinates of the paddle*/
	for (int i = 0; i < paddle.size(); i++) {
		term::set_cell(paddle[i].x, paddle[i].y, '#');
	}
}


void draw_gameover()
{
	std::string over_text = "Game Over!";
	std::string reset_text = "Press 'e' to restart.";

	int half_width = term::width() / 2;
	int half_height = term::height() / 2;

	term::draw_text(half_width - over_text.size()/2, half_height, over_text);
	term::draw_text(half_width - reset_text.size()/2, half_height + 1, reset_text);
}

void move_paddle(std::vector<Vec2D>& paddle, Direction dir)
{
	/*
		Moves the paddle to its new position.
		To move the paddle to its new position,
		one has to move all the elements of the paddle
		in y-direction.
		@param paddle is a vector that contains the current x and y coordinates of the paddle
		@param dir contains the name of the dirction
	*/
	if (dir == DOWN) {
		for (int i = 0; i < paddle.size(); i++) {
			paddle[i].y = paddle[i].y + 1;
		}
	}
	if (dir == UP) {
		for (int i = 0; i < paddle.size(); i++) {
			paddle[i].y = paddle[i].y - 1;
		}
	}
}

void move_ball(Vec2D& ball, Vec2D velocity)
{
	/*Moves the ball to its new position depending
		on the velocity.
		@param ball contains the current x and y coordinate of the ball
		@param velocity contains the current velocity in x and y direction
		Note: the velocity is the increment of the x and y coordinates respectively
		Note: the integration over time is done by the sleep function in main*/
		ball.x = ball.x + velocity.x;
		ball.y = ball.y + velocity.y;
}

bool check_collision_ball_rl(Vec2D ball)
{
	/*Check whether the ball collides with the right and left border.
		@param ball contains the current x and y coordinate of the ball*/
	if (ball.x == 0 || ball.y == term::width()) {
		return true;
	}
	return false;
}


bool check_collision_ball_ul(Vec2D ball)
{
	/*Check whether the ball collides with the upper and lower border.
		@param ball contains the current x and y coordinate of the ball*/
	if (ball.y == 0 || ball.y == term::height()) {
		return true;
	}
	return false;
}

bool check_collision_ball_paddle(const std::vector<Vec2D>& paddle, Vec2D ball)
{
	/*Check whether the ball collides with a paddle
		@param paddle is a vector that contains the current x and y coordinates of the paddle
		@param ball contains the current x and y coordinate of the ball*/
	for (int i = 0; i < paddle.size(); i++) {
		if (paddle[i].x == ball.x && paddle[i].y == ball.y) {
			return true;
		}
	}

	return false;
}

bool check_collision_paddle_border(const std::vector<Vec2D>& paddle)
{
	/* Check whether the paddle collides with the border */
		if (paddle[0].y == 0 || paddle[paddle.size()-1].y == term::height()) {
			return true;
		}
	return false;
}

// Initial left paddle segment coordinates.
std::vector<Vec2D> initialize_left_paddle()
{
	return { {3, 14}, {3, 15}, {3, 16}, {3, 17}, {3, 18}, {3, 19}, {3, 20},  {3, 21}, {3, 22}, {3, 23} };
}

// Initial right paddle segment coordinates.
std::vector<Vec2D> initialize_right_paddle()
{
	return { { 76, 14 },{ 76, 15 },{ 76, 16 },{ 76, 17 },{ 76, 18 },{ 76, 19 },{ 76, 20 },{ 76, 21 },{ 76, 22 },{ 76, 23 } };
}

int main()
{
	term::initialize(80, 30);
	int time = 100;

	bool game_over = false;
	Vec2D ball = { 5, 14 };
	Vec2D velocity = { 1, 1 };
	std::vector<Vec2D> left_paddle = initialize_left_paddle();
	std::vector<Vec2D> right_paddle = initialize_right_paddle();
	Direction left_paddle_dir = UP;
	Direction right_paddle_dir = DOWN;


	while (true) {
		if (!game_over) {
			term::clear();
			/*Draw the playing field with border, ball, left and right paddle*/
			draw_border();
			draw_ball(ball);
			draw_paddle(left_paddle);
			draw_paddle(right_paddle);
		}

		switch (term::get_key()) {
			case 's':
				left_paddle_dir = DOWN;
				break;

			case 'w':
				left_paddle_dir = UP;
				break;

			case 'l':
				right_paddle_dir = DOWN;
				break;

			case 'o':
				right_paddle_dir = UP;
				break;

			case 'e':
				// restart the game
				time = 100;
				left_paddle_dir = DOWN;
				right_paddle_dir = UP;
				game_over = false;
				ball = { 4, 14 };
				velocity = { 1, 1 };
				left_paddle = initialize_left_paddle();
				right_paddle = initialize_right_paddle();
				break;

			case 'q':
				term::close();
				return 0;
		}

		if (!game_over) {
			/* Move the paddles and the ball and check for collisions */
			move_ball(ball,velocity);

			if (check_collision_paddle_border(left_paddle)) {
				if (left_paddle_dir == UP) {
					left_paddle_dir = DOWN;
				}else
				if (left_paddle_dir == DOWN) {
					left_paddle_dir = UP;
				}
			}
			if (check_collision_paddle_border(right_paddle)) {
				if (right_paddle_dir == UP) {
					right_paddle_dir = DOWN;
				}else
				if (right_paddle_dir == DOWN) {
					right_paddle_dir = UP;
				}
			}
			move_paddle(right_paddle, right_paddle_dir);
			move_paddle(left_paddle, left_paddle_dir);

			if (check_collision_ball_ul(ball)) {
				velocity.y = velocity.y * -1;
			}

			if (check_collision_ball_paddle(left_paddle,ball) || check_collision_ball_paddle(right_paddle,ball)) {
				velocity.x = velocity.x * -1;
			}

			if (check_collision_ball_rl(ball)) {
				game_over = true;
			}

		}
		else {
			draw_gameover();
		}

		term::sleep(time);
	}

	return 0;
}
