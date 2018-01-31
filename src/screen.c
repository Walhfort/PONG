#include "const.h"

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
				break;
			case BORDER:
				color(white);
				break;

			case PADDLE:
				color(blue);
				break;
			case BALL:
				color(yellow);
				break;
			}
			printf("\u2588");
		}
		printf("\n");
	}

}
