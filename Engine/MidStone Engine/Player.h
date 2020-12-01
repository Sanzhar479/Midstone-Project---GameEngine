#pragma once
#include "Object.h"
using namespace MATH;
	class Player : public Object
	{
	public:
		const Uint8* state = SDL_GetKeyboardState(NULL);
		float vel;
		Player();
		Player(float vel_);
		~Player();
		void Update(const float deltaTime);
		void Control(const float deltaTime);
		Vec3 dir;
		void Block(Object object);
		void Death(Object object);
	};