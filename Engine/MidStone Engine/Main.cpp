#include "SDL.h"
#include "Game.h"
#include "Player.h"
#include <SDL.h>
//#include <SDL_image.h>

int main(int argc, char* argv[])
{
	//OnCreate
	const int FPS = 60;
	const int frameDelay = 1000 / FPS;
	Uint32 frameStart;
	int frameTime;
	Game* game = new Game();
	Player* player = new Player(Vec2D(1.0f, 1.0f), 5.0f);
	game->init("GameWindow", 800, 640, false);
	//Update
    while (game->running())
	{
		player->Update(0.5);
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