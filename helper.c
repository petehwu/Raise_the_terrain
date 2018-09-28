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
	int lroto = roto->left * 10, rroto = roto->right * 10;
	float src_wx, src_wy, tgt_wx, tgt_wy;
	float src_rx, src_ry, tgt_rx, tgt_ry;
	float angle = 0;

	angle = ((lroto - rroto) * M_PI) / 180;
	src_wx = .7 * x - .7 * y;
	src_wy = .3 * x + .3 * y - (z1 * (i * .002));
	tgt_wx = .7 * x - .7 * (y + SQUARE_SIZE);
	tgt_wy = .3 * x + .3 * (y + SQUARE_SIZE) - (z2 * (i * .002));

	src_rx = src_wx * cos(angle) - src_wy * sin(angle);
	src_ry = src_wx * sin(angle) + src_wy * cos(angle);
	tgt_rx = tgt_wx * cos(angle) - tgt_wy * sin(angle);
	tgt_ry = tgt_wx * sin(angle) + tgt_wy * cos(angle);

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
	int lroto = roto->left * 10, rroto = roto->right * 10;
	float src_wx, src_wy, tgt_wx, tgt_wy;
	float src_rx, src_ry, tgt_rx, tgt_ry;
	float angle = 0;

	angle = ((lroto - rroto) * M_PI) / 180;
	src_wx = .7 * x - .7 * y;
	src_wy = .3 * x + .3 * y - (z1 * (i * .002));
	tgt_wx = .7 * (x + SQUARE_SIZE) - .7 * y;
	tgt_wy = .3 * (x + SQUARE_SIZE) + .3 * y - (z2 * (i * .002));

	src_rx = src_wx * cos(angle) - src_wy * sin(angle);
	src_ry = src_wx * sin(angle) + src_wy * cos(angle);
	tgt_rx = tgt_wx * cos(angle) - tgt_wy * sin(angle);
	tgt_ry = tgt_wx * sin(angle) + tgt_wy * cos(angle);
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

	roto->left = 0;
	roto->right = 0;
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
