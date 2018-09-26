#include "header.h"
#include "stdio.h"

void draw_stuff(SDL_Instance instance, char *filename)
{
	FILE *ifp;
	  char *mode = "r";
	int row, col;
	int sx, sy, tx, ty;
	int ssx, ssy, ttx, tty, r = 0, rn = 1, c = 0, n = 1, i;
	int z[8][8] = {
		{0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0}
	};

	ifp = fopen(filename, mode);
	if (!ifp)
	{
		fprintf(stderr, "Can't open input file %s\n", filename);
		exit(1);
	}
	for (i = 0; i < 8; i++)
		fscanf(ifp, "%d %d %d %d %d %d %d %d", &z[i][0], &z[i][1], &z[i][2], &z[i][3],
			&z[i][4], &z[i][5], &z[i][6], &z[i][7]);	
	fclose(ifp);

for (i = 0; i <= 500; i++)
{
	r = 0;
	rn = 1;
	c = 0;
	n = 1;
	SDL_SetRenderDrawColor(instance.renderer, 0,0,0,0);
	SDL_RenderClear(instance.renderer);
	SDL_SetRenderDrawColor(instance.renderer, 0XFF, 0XFF, 0XFF, 0XFF);
	for (row = -200; row <= 490; row +=115 )
	{
		for (col = 650; col <= 1340; col+=115)
		{
			sx = col;
			sy = row;
			tx = col + 115;
			ty = row;
			ssx = .7 * sx - .7 * sy;
			ssy = (1 - .7) * sx + (1 - .7) * sy - (z[r][c] * (i * .002));
			ttx = .7 * tx - .7 * ty;
			tty = (1 - .7) * tx + (1 - .7) * ty - (z[r][n] * (i * .002)); 
			SDL_RenderDrawLine(instance.renderer, ssx, ssy, ttx, tty);
			//SDL_RenderDrawLine(instance.renderer, sx, sy, tx, ty);
			sx = col;
			sy = row;
			tx = col;
			ty = row + 115;
			ssx = .7 * sx - .7 * sy;
			ssy = (1 - .7) * sx + (1 - .7) * sy - (z[r][c] * (i * .002));
			ttx = .7 * tx - .7 * ty;
			tty = (1 - .7) * tx + (1 - .7) * ty - (z[rn][c] * (i * .002));
			SDL_RenderDrawLine(instance.renderer, ssx, ssy, ttx, tty);
			//SDL_RenderDrawLine(instance.renderer, sx, sy, tx, ty);
			if (row == 490)
			{
				sx = col;
				sy = row + 115;
				tx = col + 115;
				ty = row + 115;
				ssx = .7 * sx - .7 * sy;
				ssy = (1 - .7) * sx + (1 - .7) * sy - (z[rn][c] * (i * .002));
				ttx = .7 * tx - .7 * ty;
				tty = (1 - .7) * tx + (1 - .7) * ty - (z[rn][n] * (i * .002));
				SDL_RenderDrawLine(instance.renderer, ssx, ssy, ttx, tty);
				//SDL_RenderDrawLine(instance.renderer, sx, sy, tx, ty);
			}
			c++;
			n++;
		}
		sx = col;
		sy = row;
		tx = col;
		ty = row + 115;
		ssx = .7 * sx - .7 * sy;
		ssy = (1 - .7) * sx + (1 - .7) * sy - (z[r][7] * (i * .002));
		ttx = .7 * tx - .7 * ty;
		tty = (1 - .7) * tx + (1 - .7) * ty - (z[rn][7] * (i * .002));
		SDL_RenderDrawLine(instance.renderer, ssx, ssy, ttx, tty);
		//SDL_RenderDrawLine(instance.renderer, sx, sy, tx, ty);
		r++;
		rn++;
		c = 0;
		n = 1;

	}
	SDL_RenderPresent(instance.renderer);
	if (i == 500)
		SDL_Delay(8000);
	else
		SDL_Delay(15);
	if (poll_events() == 1)
	{
		SDL_DestroyRenderer(instance.renderer);
		SDL_DestroyWindow(instance.window);
		SDL_Quit();
		exit(0);
	}
}

}
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

int poll_events()
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
				if (key.keysym.scancode == 0x29)
					return (1);
				break;
		}
	}
	return (0);
}
