#include "header.h"

void draw_stuff(SDL_Instance instance, char *filename)
{
	FILE *ifp;
	char *mode = "r";
	int sx, sy, tx, ty;

	ifp = fopen(filename, mode);
	if (!ifp)
	{
		fprintf(stderr, "Can't open input file %s\n", filename);
		exit(1);
	}
	SDL_SetRenderDrawColor(instance.renderer, 0XFF, 0XFF, 0XFF, 0XFF);
	while( fscanf(ifp, "%d, %d, %d, %d", &sx, &sy, &tx, &ty) != EOF)
	{
		SDL_RenderDrawLine(instance.renderer, sx, sy, tx, ty);
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
