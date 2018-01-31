#include "const.h"

int main(){
	int size_x = 121, size_y = 31;
	int middle_y = size_y / 2, middle_x = size_x /2;

	grid_t * grid = init_grid(size_x,size_y);
	build(grid);

	//Create Ball
	ball_t ball;
	ball.curr = set_pos(3, middle_y -2);
	ball.vect = set_pos(2, 1);
	ball.last_char = VOID;

	//Create Players
	pos_t player1 = set_pos(1, middle_y);
	pos_t player2 = set_pos(size_x-2, middle_y);

	move_paddle(grid, player1, 0);
	move_paddle(grid, player2, 0);

	print(grid);
	for(int i = 0; i < 1500; i++){
		ball = move_ball(grid,ball, player1, player2);

		if(ball.curr.x < middle_x && ball.vect.x < 0) 
			player1 = move_paddle(grid, player1, player1.y + LENGHT_PADDLE/2 - ball.curr.y > 0 ? -1:1);

		if(ball.curr.x > middle_x && ball.vect.x > 0) 
			player2 = move_paddle(grid, player2, player2.y + LENGHT_PADDLE/2 - ball.curr.y > 0 ? -1:1);
		
		print(grid);
		usleep(30000);
	}

	free_grid(grid);
	return 0;
}


