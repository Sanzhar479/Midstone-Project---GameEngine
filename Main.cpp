#include "SDL.h"
#include "Game.h"

Game* game = nullptr;

int main(int argc, char* argv[])
{
	const int FPS = 60;
	const int frameDelay = 1000 / FPS;
	Uint32 frameStart;
	int frameTIme;
	game = new Game();

	game->init("GameWindow", 800, 640, false);
	
    while (game->running())
	{
		frameStart = SDL_GetTicks();

		frameTIme = SDL_GetTicks() - frameStart;
		if (frameDelay > frameTIme) {
			SDL_Delay(frameDelay - frameTIme);
		}

	}

return 0;
}