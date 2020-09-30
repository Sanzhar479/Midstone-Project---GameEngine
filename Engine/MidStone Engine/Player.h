#pragma once
#include "SDL.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include "Vec2D.h"
	class Player
	{
	public:
		const Uint8* state = SDL_GetKeyboardState(NULL);
		Vec2D pos;
		float vel;
		float xdir = 0.0f;
		float ydir = 0.0f;
		//Vec2D Dir;
		Player();
		Player(Vec2D pos_, float vel_);
		~Player();
		void Update(const float deltaTime);
		Vec2D GetPos();
		Vec2D dir();
	};