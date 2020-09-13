#include "SDL.h"
#include "Game.h"

int main(int argc, char* argv[])
{
	const int FPS = 60;
	const int frameDelay = 1000 / FPS;
	Uint32 frameStart;
	int frameTime;
	Game* game = new Game();

	game->init("GameWindow", 800, 640, false);
	
    while (game->running())
	{
		frameStart = SDL_GetTicks();

		frameTime = SDL_GetTicks() - frameStart;
		if (frameDelay > frameTime) {
			SDL_Delay(frameDelay - frameTime);
		}
		game->quit();
	}
SDL_Quit();
return 0;
}