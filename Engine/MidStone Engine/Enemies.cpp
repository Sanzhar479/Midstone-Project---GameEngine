#include "Enemies.h"
Enemies::Enemies() : Object() {
	vel = 0.0f;
	dir = Vec3(0.0f, 0.0f, 0.0f);
}
Enemies::Enemies(float vel_, Spawner* spawner) {
	vel = vel_;
	dir = Vec3(0.0f, 0.0f, 0.0f);
	image = IMG_Load("Sprites/enemy.png");
	sizeH = 64;
	sizeW = 64;
	pos = spawner->Rand();
}
bool Enemies::Damage(Player* player) {
	if (CollisionDetected(player) == true) {
		player->health--;
		return true;
	}
	return false;
}
void Enemies::AIChasing(Player* player) {
	dir = player->pos - pos;
	float mag = sqrt(dir.x * dir.x + dir.y * dir.y);
	dir = Vec3(dir.x / mag, dir.y / mag, 0.0f);
}
void Enemies::Update(const float deltaTime) {
	pos += dir * vel * deltaTime;
}
Enemies::~Enemies() {

}