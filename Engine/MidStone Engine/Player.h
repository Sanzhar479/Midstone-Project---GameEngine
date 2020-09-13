#pragma once
#include "SDL.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include "Vec3.h"
	class Player
	{
	public:
		Vec3 pos;
		Vec3 vel;
		Vec3 accel;
		float mass;
		Player();
		Player(Vec3 pos_, Vec3 vel_, Vec3 accel_, float mass_);
		~Player();
		void Update(const float deltaTime);
		void ApplyForce(Vec3 force);
		Vec3 GetPos();

	};