#include <SDL2/SDL.h>
#include "header.h"

int main(void)
{
	SDL_Instance instance;
	char filename[20] = "";

	printf("Enter the filename(20 characters max) to use:\n");
	scanf("%s", filename);

	if (init_instance(&instance) != 0)
		return (1);

	while ("C is awesome")
	{
		SDL_SetRenderDrawColor(instance.renderer, 0,0,0,0);
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
