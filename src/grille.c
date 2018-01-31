#include "const.h"

//Create - Destruct
grid_t * init_grid(int size_x, int size_y){
	int size = size_x * size_y; 

	//Dynamic Memory
	grid_t * array = (grid_t*) malloc(sizeof(grid_t));
	array->size_x = size_x;
	array->size_y = size_y;
	array->grid = (int*) malloc(size * sizeof(int));
	
	//Set all cells at 0
	for(int i = 0; i < size; i++){
		array->grid[i] = VOID;
	}
	return array;
}

void free_grid(grid_t * array){
	free(array->grid);
	free(array);
}

//Index - Read - Write
int index(const grid_t * grid, int l, int c){
	return l*(grid->size_y) + c;
}

int read_cell(const grid_t * array, int l, int c){
	return array->grid[index(array, l, c)];
}

void write_cell(grid_t * array, int l, int c, int value){
	array->grid[index(array, l, c)] = value;
}




