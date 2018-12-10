#include "const.h"

pos_t set_pos(int x, int middle_y){
	pos_t pos;

	pos.x = x;
	pos.y = middle_y - LENGHT_PADDLE / 2;

	return pos;
}

void print(grid_t * grid){
	system("clear");
	int size_x = grid->size_x;
	int size_y = grid->size_y;
	int cell;

	printf("PONG v%s\n\n",VERSION);

	for(int y = 0; y < size_y; y++){
		for(int x = 0; x < size_x; x++){
			cell = read_cell(grid, x, y);
			switch(cell){
			case VOID:
				color(green);
				printf("\u2588");
				break;
			case BORDER:
				color(white);
				printf("\u2588");
				break;

			case PADDLE:
				color(blue);
				printf("\u2588");
				break;
			case BALL:
				color(red);
				color(back_green);
				printf("\u25C9");
				color(reset);
				break;
			}
			
		}
		printf("\n");
	}

}

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

void update_ball(grid_t * grid, ball_t ball, pos_t player1, pos_t player2){
	write_cell(grid, ball.curr.x, ball.curr.y, ball.last_char); //Efface la balle
	ball = move_ball(grid, ball, player1, player2);
	ball.last_char = read_cell(grid, ball.curr.x, ball.curr.y);
	write_cell(grid, ball.curr.x, ball.curr.y, BALL);
}

int can_bounce(ball_t ball, pos_t player){
	int next_y = ball.curr.y + ball.vect.y;

	if(next_y <= player.y + LENGHT_PADDLE)
		return 1;
	else
		return 0;

}

ball_t move_ball(grid_t * grid, ball_t ball, pos_t player1, pos_t player2){
	
	int size_y = grid->size_y;

	int next_x = ball.curr.x + ball.vect.x;
	int next_y = ball.curr.y + ball.vect.y;

	if(next_x <= player1.x)
		if(can_bounce(ball, player1)){
			update_ball(grid, ball, player1, player2);
			ball.vect.x = 0 - ball.vect.x;
		}
		else
			ball.vect.x = 0;


	else{
		if(next_x >= player2.x) {
			if(can_bounce(ball, player2))
				ball.vect.x = 0 - ball.vect.x;
			else
				ball.vect.x = 0;
		}

	}
	
	if(next_y > size_y -2 || next_y < 1)
		ball.vect.y = 0 - ball.vect.y;

	ball.curr.x += ball.vect.x;
	ball.curr.y += ball.vect.y;
	
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





