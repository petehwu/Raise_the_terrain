#include <SDL2/SDL.h>
#include "header.h"

coords *cd = NULL;
/**
 * main - main entry point to the program
 * @argc: number of arguments included
 * @argv: list of arguments passed in with program
 * Return: always 0
 */
int main(int argc, char **argv)
{
	int i, j;
	FILE *ifp;
	char *filename = NULL;
	char MODE = 'r';
	SDL_Instance instance;

	if (argc != 2)
	{
		printf("Usage: terrain file\n");
		exit(1);
	}
	filename = argv[1];
	if (init_instance(&instance) != 0)
		return (1);
	cd = malloc(sizeof(coords));
	/* initialize all values in cd to 0*/
	cd->left = 0;
	cd->right = 0;
	for (i = 0; i < 8 ; i++)
		for (j = 0; j < 8; j++)
		{
			cd->z[i][j] = 0;
		}
        ifp = fopen(filename, mode);
        if (!ifp)
        {
                fprintf(stderr, "Can't open input file %s\n", filename);
                exit(1);
        }
        for (i = 0; i < 8; i++)
                fscanf(ifp, "%d %d %d %d %d %d %d %d", &(cd->z[i][0]), &(cd->z[i][1]),
                                &(cd->z[i][2]), &(cd->z[i][3]), &(cd->z[i][4]),
				&(cd->z[i][5]), &(cd->z[i][6]), &(cd->z[i][7]));
        fclose(ifp);


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
