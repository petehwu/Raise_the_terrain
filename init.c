#include "header.h"

void draw_stuff(SDL_Instance instance, char *filename)
{
	FILE *ifp;
	char *mode = "r";
	int row, col;
	int sx, sy, sz, tx, ty, tz;
	int ssx, ssy, ttx, tty;
	int i;

	ifp = fopen(filename, mode);
	if (!ifp)
	{
		fprintf(stderr, "Can't open input file %s\n", filename);
		exit(1);
	}
	for (i = 0; i <= 500; i++)
	{
		SDL_SetRenderDrawColor(instance.renderer, 0,0,0,0);
		SDL_RenderClear(instance.renderer);
		SDL_SetRenderDrawColor(instance.renderer, 0XFF, 0XFF, 0XFF, 0XFF);
		while( fscanf(ifp, "%d, %d, %d, %d, %d, %d", &sx, &sy, &sz, &tx, &ty, &tz) != EOF)
		{ 
			ssx = .7 * sx - .7 * sy;
			ssy = (1 - .7) * sx + (1 - .7) * sy - (sz * (i * .002));
			ttx = .7 * tx - .7 * ty;
			tty = (1 - .7) * tx + (1 - .7) * ty - (tz * (i * .002));
			SDL_RenderDrawLine(instance.renderer, ssx, ssy, ttx, tty);

		}
		SDL_RenderPresent(instance.renderer);
		if (i == 500)
			SDL_Delay(8000);
		else
		 SDL_Delay(50);
		rewind(ifp);
		if (poll_events() == 1)
			exit(0);
	}


	fclose(ifp); 

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
