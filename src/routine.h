#ifndef routine
#define routine

typedef struct{
	int x;
	int y;
}pos_t;

typedef struct{
	pos_t curr;
	pos_t vect;
	int last_char;
}ball_t;

pos_t set_pos(int, int);

void print(grid_t *);
void build(grid_t *);


void update_ball(grid_t*, ball_t);
int can_bounce(ball_t, pos_t);
ball_t move_ball(grid_t *, ball_t, pos_t, pos_t);

pos_t move_paddle(grid_t * grid, pos_t paddle, int dir);


#endif
