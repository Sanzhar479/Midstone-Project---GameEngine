#pragma once
#include "SDL.h"
#include <iostream>
#include <vector>

class Game
{
public:
	Game();
	~Game();

	bool running() { return isRunning; }
	void init(const char* title, int width, int height, bool fullscreen);
	void render();

	static SDL_Renderer* renderer;
	static bool isRunning;


private:

	int cnt = 0;
	SDL_Window* window;

};

