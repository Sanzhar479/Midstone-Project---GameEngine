#pragma once
#include "SDL.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include "Vector.h"
#include "VMath.h"
using namespace MATH;
	class Player
	{
	public:
		const Uint8* state = SDL_GetKeyboardState(NULL);
		Vec3 pos;
		float vel;
		float xdir = 0.0f;
		float ydir = 0.0f;
		SDL_Surface* image;
		void Render(SDL_Window* window_);
		Player();
		Player(Vec3 pos_, float vel_, SDL_Surface* image_);
		~Player();
		void Update(const float deltaTime);
		Vec3 GetPos();
		Vec3 dir();
	};