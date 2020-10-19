#pragma once
#include "SDL.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include "Vector.h"
#include "VMath.h"
#include "Object.h"
using namespace MATH;
	class Player
	{
	public:
		const Uint8* state = SDL_GetKeyboardState(NULL);
		Vec3 pos;
		float vel;
		int sizeW, sizeH;
		SDL_Surface* image;
		void Render(SDL_Window* window_);
		Player();
		Player(Vec3 pos_, float vel_, SDL_Surface* image_, int sizeH_, int sizeW_);
		~Player();
		void Update(const float deltaTime);
		Vec3 GetPos();
		Vec3 dir = Vec3(0.0f, 0.0f, 0.0f);
		bool CollisionDetected(Object object_);
	};