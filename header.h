#ifndef _HEADER_H_
#define _HEADER_H_

#include <SDL2/SDL.h>
#include <unistd.h>
/**
 * struct roto_s- keeps track of z axis values and left and right key presses to rotate the rendered image
 * @left: number of times left key pressed
 * @right: number of times right key pressed
 */

typedef struct roto_s {
        int left;
        int right;
	int z[8][8];
} roto;

extern coord *coords;

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
void draw_stuff(SDL_Instance instance, char *filename);
int poll_events(void);
coord *calc_vert(coord *coords, int row, int col, int z1, int z2, int i);
coord *calc_hori(coord *coords, int row, int col, int z1, int z2, int i);

#endif
