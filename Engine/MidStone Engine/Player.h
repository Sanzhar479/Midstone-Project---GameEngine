#pragma once
#include "Object.h"
using namespace MATH;
	class Player : public Object
	{
	public:
		//setting ability to get key input
		const Uint8* state = SDL_GetKeyboardState(NULL);
		//speed of the player
		float vel;
		//if player is blocked by other object
		bool blockedx = false;
		bool blockedy = false;
		int health;
		int score;
		Player();
		//setting player
		Player(float vel_, int health_, int score_);
		~Player();
		//updating all variables of the player
		void Update(const float deltaTime);
		//keyboard control
		void Control();
		//direction of the playermovement
		Vec3 dir;
		//blocking movement
		void Block(Object* object);
		//finishing game
		bool Death();
	};