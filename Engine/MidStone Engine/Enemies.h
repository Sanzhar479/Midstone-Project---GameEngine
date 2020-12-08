#pragma once
#include "Object.h"
#include "Player.h"

class Enemies : public Object
{
public:
	float vel;
	Vec3 dir;
	void Update(const float deltaTime);
	void AIChasing(Player* player);
	void Damage(Player* player);
	Enemies();
	Enemies(float vel_);
	~Enemies();
};

