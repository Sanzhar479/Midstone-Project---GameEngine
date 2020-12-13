#pragma once
#include "Object.h"
#include "Player.h"
#include "Spawner.h"
class Enemies : public Object
{
public:
	float vel;
	Vec3 dir;
	void Update(const float deltaTime);
	void AIChasing(Player* player);
	bool Damage(Player* player);
	Enemies();
	Enemies(float vel_, Spawner* spawner);
	~Enemies();
};

