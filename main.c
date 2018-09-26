#include <SDL2/SDL.h>
#include "header.h"
/**
 * main - main entry point to the program
 * @argc: number of arguments included
 * @argv: list of arguments passed in with program
 * Return: always 0
 */
int main(int argc, char **argv)
{
	char *filename = NULL;
	SDL_Instance instance;

	if (argc != 2)
	{
		printf("Usage: terrain file\n");
		exit(1);
	}
	filename = argv[1];
	if (init_instance(&instance) != 0)
		return (1);

	while ("C is awesome")
	{
		SDL_SetRenderDrawColor(instance.renderer, 0, 0, 0, 0);
		SDL_RenderClear(instance.renderer);
		if (poll_events() == 1)
			break;
		draw_stuff(instance, filename);
		SDL_RenderPresent(instance.renderer);
	}
	SDL_DestroyRenderer(instance.renderer);
	SDL_DestroyWindow(instance.window);
	SDL_Quit();
	return (0);
}
