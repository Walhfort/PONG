#include "const.h"

void build(grid_t * grid){
	int size_x = grid->size_x;
	int size_y = grid->size_y;
	int middle_x = size_x / 2;	

	for(int i = 0; i < size_x; i++){
		write_cell(grid, i, 0, BORDER);
		write_cell(grid, i, size_y-1, BORDER);
	}
	for(int i = 0; i < size_y; i++){
		write_cell(grid, 0, i, BORDER);
		write_cell(grid, size_x-1, i, BORDER); 
		write_cell(grid, middle_x, i, BORDER);
	}
}

ball_t move_ball(grid_t * grid, ball_t ball, pos_t player1, pos_t player2){
	write_cell(grid, ball.curr.x, ball.curr.y, ball.last_char); //Efface la balle
	
	int size_y = grid->size_y;

	int next_x = ball.curr.x + ball.vect.x;
	int next_y = ball.curr.y + ball.vect.y;

	if(next_x <= player1.x)
		if(next_y >= player1.y && next_y <= player1.y + LENGHT_PADDLE)
			ball.vect.x = 0 - ball.vect.x;
		else
			ball.vect.x = 0;


	else{
		if(next_x >= player2.x) {
			if(next_y >= player2.y && next_y <= player2.y + LENGHT_PADDLE)
				ball.vect.x = 0 - ball.vect.x;
			else
				ball.vect.x = 0;
		}

	}
	if(next_y > size_y -2 || next_y < 1)
		ball.vect.y = 0 - ball.vect.y;

	ball.curr.x += ball.vect.x;
	ball.curr.y += ball.vect.y;

	ball.last_char = read_cell(grid,ball.curr.x, ball.curr.y);
	
	write_cell(grid, ball.curr.x, ball.curr.y, BALL);
	
	return ball;
}

pos_t move_paddle(grid_t * grid, pos_t paddle, int dir){
	int x = paddle.x;
	int y = paddle.y;	
	
	if(dir == 0){
		for(int i = y ; i < y + LENGHT_PADDLE; i++){
			write_cell(grid, x, i + dir, PADDLE);

		}
	}
	else {
		if(dir == -1 && y > 1){ // monter	
		
			write_cell(grid, x, y+LENGHT_PADDLE-1, VOID);
			for(int i = y ; i < y + LENGHT_PADDLE; i++){
				write_cell(grid, x, i + dir, PADDLE);

			}


			paddle.y += dir;
		}
		else if(dir == 1 && y < grid->size_y - LENGHT_PADDLE-1){
			write_cell(grid, x, y, VOID);
			for(int i = y ; i < y + LENGHT_PADDLE; i++){
				write_cell(grid, x, i + dir, PADDLE);

			}
			paddle.y += dir;
		}
	}
	

	return paddle;
}





