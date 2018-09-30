#include "header.h"


/**
 * calc_vert - calculates coordinates for the vertical lines
 * @coords: struct containing coordinates
 * @x: raw x value
 * @y: raw y value
 * @z1: starting z value
 * @z2: ending z value
 * @i: increment
 * Return: coord struct
 */
coord *calc_vert(coord *coords, int y, int x, int z1, int z2, int i)
{
	float src_wx, src_wy, tgt_wx, tgt_wy;
	float src_rx, src_ry, tgt_rx, tgt_ry;
	float angle = 0;
	float inc = INCLINATION;
	float x_offset = 590, y_offset = 360;


	angle = (roto->degree * M_PI) / 180;
	src_wx = inc * x - inc * y;
	src_wy = (1 - inc) * x + (1 - inc) * y - (z1 * (i * .002));
	tgt_wx = inc * x - inc * (y + SQUARE_SIZE);
	tgt_wy = (1 - inc) * x + (1 - inc) * (y + SQUARE_SIZE) - (z2 * (i * .002));

	src_wx -= x_offset;
	src_wy -= y_offset;
	tgt_wx -= x_offset;
	tgt_wy -= y_offset;
	src_rx = src_wx * cos(angle) - src_wy * sin(angle);
	src_ry = src_wx * sin(angle) + src_wy * cos(angle);
	tgt_rx = tgt_wx * cos(angle) - tgt_wy * sin(angle);
	tgt_ry = tgt_wx * sin(angle) + tgt_wy * cos(angle);
	src_rx += x_offset;
	src_ry += y_offset;
	tgt_rx += x_offset;
	tgt_ry += y_offset;


	coords->ssx = src_rx;
	coords->ssy = src_ry;
	coords->ttx = tgt_rx;
	coords->tty = tgt_ry;

	return (coords);

}
/**
 * calc_hori - calculates coordinates for the horizontal lines
 * @coords: struct containing coordinates
 * @x: raw x value
 * @y: raw y value
 * @z1: starting z value
 * @z2: ending z value
 * @i: increment
 * Return: coord struct
 */
coord *calc_hori(coord *coords, int y, int x, int z1, int z2, int i)
{
	float src_wx, src_wy, tgt_wx, tgt_wy;
	float src_rx, src_ry, tgt_rx, tgt_ry;
	float angle = 0;
	float inc = INCLINATION;
	float x_offset = 590, y_offset = 360;


	angle = (roto->degree * M_PI) / 180;
	src_wx = inc * x - inc * y;
	src_wy = (1 - inc)  * x + (1 - inc) * y - (z1 * (i * .002));
	tgt_wx = inc * (x + SQUARE_SIZE) - inc * y;
	tgt_wy = (1 - inc) * (x + SQUARE_SIZE) + (1 - inc) * y - (z2 * (i * .002));

	src_wx -= x_offset;
	src_wy -= y_offset;
	tgt_wx -= x_offset;
	tgt_wy -= y_offset;
	src_rx = src_wx * cos(angle) - src_wy * sin(angle);
	src_ry = src_wx * sin(angle) + src_wy * cos(angle);
	tgt_rx = tgt_wx * cos(angle) - tgt_wy * sin(angle);
	tgt_ry = tgt_wx * sin(angle) + tgt_wy * cos(angle);
	src_rx += x_offset;
	src_ry += y_offset;
	tgt_rx += x_offset;
	tgt_ry += y_offset;
	coords->ssx = src_rx;
	coords->ssy = src_ry;
	coords->ttx = tgt_rx;
	coords->tty = tgt_ry;

	return (coords);
}
/**
 * init_roto - initializes the global variable
 * @filename: name of the file to use
 * Return: 0 if successfule 1 otherwise
 */

int init_roto(char *filename)
{
	FILE *ifp;
	char *mode = "r";
	int i, j;

	roto->degree = 0;
	for (i = 0; i < 8 ; i++)
		for (j = 0; j < 8; j++)
		{
			roto->z[i][j] = 0;
		}
	ifp = fopen(filename, mode);
	if (!ifp)
	{
		fprintf(stderr, "Can't open input file %s\n", filename);
		return (1);
	}
	for (i = 0; i < 8; i++)
		fscanf(ifp, "%d %d %d %d %d %d %d %d", &(roto->z[i][0]), &(roto->z[i][1]),
				&(roto->z[i][2]), &(roto->z[i][3]), &(roto->z[i][4]),
				&(roto->z[i][5]), &(roto->z[i][6]), &(roto->z[i][7]));
	fclose(ifp);
	return (0);

}
/**
 * do_exit - cleans up window and exits
 * @instance: the SDLinstance
 * @cd: struct used for coordinates
 */
void do_exit(SDL_Instance instance, coord *cd)
{
	SDL_DestroyRenderer(instance.renderer);
	SDL_DestroyWindow(instance.window);
	SDL_Quit();
	free(cd);
	free(roto);
	exit(0);
}
