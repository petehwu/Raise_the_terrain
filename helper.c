#include "header.h"


/**
 * calc_vert - calculates coordinates for the vertical lines
 * @coords: struct containing coordinates
 * @row: raw x value
 * @col: raw y value
 * @z1: starting z value
 * @z2: ending z value
 * @i: increment
 * Return: coord struct
 */
coord *calc_vert(coord *coords, int row, int col, int z1, int z2, int i)
{
	coords->ssx = .7 * col - .7 * row;
	coords->ssy = (1 - .7) * col + (1 - .7) * row - (z1 * (i * .002));
	coords->ttx = .7 * col - .7 * (row + 115);
	coords->tty = (1 - .7) * col + (1 - .7) * (row + 115) - (z2 * (i * .002));
	return (coords);

}
/**
 * calc_hori - calculates coordinates for the horizontal lines
 * @coords: struct containing coordinates
 * @row: raw x value
 * @col: raw y value
 * @z1: starting z value
 * @z2: ending z value
 * @i: increment
 * Return: coord struct
 */
coord *calc_hori(coord *coords, int row, int col, int z1, int z2, int i)
{
	coords->ssx = .7 * col - .7 * row;
	coords->ssy = (1 - .7) * col + (1 - .7) * row - (z1 * (i * .002));
	coords->ttx = .7 * (col + 115) - .7 * row;
	coords->tty = (1 - .7) * (col + 115) + (1 - .7) * row - (z2 * (i * .002));
	return (coords);
}

