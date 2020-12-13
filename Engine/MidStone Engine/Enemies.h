#pragma once
#include "Object.h"
#include "Player.h"
#include "Spawner.h"
class Enemies : public Object
{
public:
	float vel;
	Vec3 dir;
	//position update
	void Update(const float deltaTime);
	//setting direction torward the player
	void AIChasing(Player* player);
	//lower player's health when they collied
	bool Damage(Player* player);
	Enemies();
	//setting enemies' variables
	Enemies(float vel_, Spawner* spawner);
	~Enemies();
};

