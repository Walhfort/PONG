#ifndef grille
#define	grille

typedef struct{
	int * grid;
	int size_x;
	int size_y;
}grid_t;

//Create - Destruct
grid_t * init_grid(int, int);
void free_grid(grid_t * array);

//Index - Read - Write
int index(const grid_t *, int l, int c);
int read_cell(const grid_t * array, int l, int c);
void write_cell(grid_t * array, int l, int c, int value);


#endif
