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
		Vec2D position;
		Vec2D velocity;
		Vec2D gravitation;

		int height = 13;
		int width = 15;
		int scale = 4;
		int speed = 3;

		Player();
		~Player();
		void PlayerStats(float x, float y, int h, int w, int sc);
		void Update() 
		{
			position.x += static_cast<int>(velocity.x * speed);
			position.y += static_cast<int>(velocity.y * speed);
		}
		
	};