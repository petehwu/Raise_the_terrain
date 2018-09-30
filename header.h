#ifndef _HEADER_H_
#define _HEADER_H_

#include <SDL2/SDL.h>
#include <unistd.h>
#include <math.h>

#define SQUARE_SIZE 70
#define INCLINATION .7
/**
 * struct rotation_s- keeps track of z axis values and angle to rotate
 * @degree:  degrees of rotation
 * @z: z coordinates read in from file
 *
 * Description:
 * each left key press will increase angle of rotation by 10 degrees
 * each right key press will decrease angle of rotation by 10 degrees
 *
 */

typedef struct rotation_s
{
	int degree;
	int z[8][8];
} rotation;

extern rotation *roto;

/**
 * struct SDL_Instance - SDL Instance for the window and the rendered
 * @window: window to draw in
 * @renderer: renderer
 */
typedef struct SDL_Instance
{
	SDL_Window *window;
	SDL_Renderer *renderer;
} SDL_Instance;

/**
 * struct coord_s - isometric projected coordinates for a line
 * @ssx: origin wx coordinate
 * @ssy: origin wy coordinate
 * @ttx: target wx coordinate
 * @tty: target wy coordinate
 */
typedef struct coord_s
{
	float ssx;
	float ssy;
	float ttx;
	float tty;
} coord;

int init_instance(SDL_Instance *);
void draw_stuff(SDL_Instance instance);
int poll_events(void);
coord *calc_vert(coord *coords, int row, int col, int z1, int z2, int i);
coord *calc_hori(coord *coords, int row, int col, int z1, int z2, int i);
int init_roto(char *filename);
void do_exit(SDL_Instance instance, coord *cd);

#endif
