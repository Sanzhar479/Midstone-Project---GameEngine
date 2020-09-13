#include "Game.h"

Game::Game()
{
}

Game::~Game()
{
}

SDL_Renderer* Game::renderer = nullptr;
bool Game::isRunning = false;

void Game::init(const char* title, int width, int height, bool fullscreen)
{
	int flags = 0;

	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		}

		isRunning = true;
	}

}

void Game::render()
{
}

void Game::quit() {
	while (SDL_PollEvent(&Events))
		{
			if (Events.type == SDL_QUIT)
				isRunning = false;
		}
}
