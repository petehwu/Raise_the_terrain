#include "header.h"
#include "stdio.h"
/**
 * draw_stuff - draws the matrix on the screen
 * @instance: the SDL_Instance window to draw the lines on
 */
void draw_stuff(SDL_Instance instance)
{
	int row, col,  r = 0, rn = 1, c = 0, n = 1, i, x_start = 775, y_start = -65;
	coord *cd = malloc(sizeof(coord));

	for (i = 0; i <= 500; i++, r = 0, rn = 1, c = 0, n = 1)
	{
		SDL_SetRenderDrawColor(instance.renderer, 0, 0, 0, 0);
		SDL_RenderClear(instance.renderer);
		SDL_SetRenderDrawColor(instance.renderer, 0XFF, 0XFF, 0XFF, 0XFF);
		for (row = y_start; row <= ((SQUARE_SIZE * 6) + y_start);
				row += SQUARE_SIZE, r++, rn++, c = 0, n = 1)
		{
			for (col = x_start; col <= ((SQUARE_SIZE) * 6 + x_start);
					col += SQUARE_SIZE, c++, n++)
			{
				cd = calc_hori(cd, row, col, roto->z[r][c], roto->z[r][n], i);
				SDL_RenderDrawLine(instance.renderer, cd->ssx, cd->ssy, cd->ttx, cd->tty);
				cd = calc_vert(cd, row, col, roto->z[r][c], roto->z[rn][c], i);
				SDL_RenderDrawLine(instance.renderer, cd->ssx, cd->ssy, cd->ttx, cd->tty);
				if (row == ((SQUARE_SIZE * 6) + y_start))
				{
					cd = calc_hori(cd, row + SQUARE_SIZE, col,
							roto->z[rn][c], roto->z[rn][n], i);
					SDL_RenderDrawLine(instance.renderer, cd->ssx,
							cd->ssy, cd->ttx, cd->tty);
				}
			}
			cd = calc_vert(cd, row, col, roto->z[r][7],
					roto->z[rn][7], i);
			SDL_RenderDrawLine(instance.renderer,
					cd->ssx, cd->ssy, cd->ttx, cd->tty);
		}
		SDL_RenderPresent(instance.renderer);
		if (i == 500)
			SDL_Delay(400);
		else
			SDL_Delay(15);
		if (poll_events() == 1)
			do_exit(instance, cd);
	}
}

/**
 * init_instance - initializes the SDL instance
 * @instance: pointer to SDL_Instance to initialize
 * Return: integer of instance number
 */
int init_instance(SDL_Instance *instance)
{
	/*init SDL*/
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		fprintf(stderr, "unable to initialize SDL: %s\n", SDL_GetError());
		return (1);
	}
	/* create a new window instance */
	instance->window = SDL_CreateWindow("SDL2 \\o/", SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED, 1180, 720, 0);
	if (instance->window == NULL)
	{
		fprintf(stderr, "SDL_CreateWindow Error: %s\n", SDL_GetError());
		SDL_Quit();
		return (1);
	}
	/* create a new rendered instance linked to the window*/
	instance->renderer = SDL_CreateRenderer(instance->window, -1,
			SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (instance->renderer == NULL)
	{
		SDL_DestroyWindow(instance->window);
		fprintf(stderr, "SDL_CreateRenderer ERror: %s\n", SDL_GetError());
		SDL_Quit();
		return (1);
	}
	return (0);
}
/**
 * poll_events - polls for keyboard input
 * Return: 1 if escape key is pressed
 */
int poll_events(void)
{
	SDL_Event event;
	SDL_KeyboardEvent key;

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			case SDL_QUIT:
				return (1);
			case SDL_KEYDOWN:
				key = event.key;
				/* if 'escape' is present */
				if (key.keysym.scancode == SDL_SCANCODE_LEFT)
					roto->degree = (roto->degree + 10) % 360;
				if (key.keysym.scancode == SDL_SCANCODE_RIGHT)
					roto->degree = (roto->degree - 10) % 360;
				if (key.keysym.scancode == 0x29)
					return (1);
				break;
		}
	}
	return (0);
}
