#pragma once
#include "Object.h"
using namespace MATH;
	class Player : public Object
	{
	public:
		const Uint8* state = SDL_GetKeyboardState(NULL);
		float vel;
		bool blockedx = false;
		bool blockedy = false;
		int health;
		int score;
		Player();
		Player(float vel_, int health_, int score_);
		~Player();
		void Update(const float deltaTime);
		void Control();
		Vec3 dir;
		void Block(Object* object);
		bool Death();
	};