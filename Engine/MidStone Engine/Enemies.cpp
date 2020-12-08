#include "Enemies.h"
Enemies::Enemies() : Object() {
	vel = 0.0f;
	dir = Vec3(0.0f, 0.0f, 0.0f);
}
Enemies::Enemies(float vel_)/* : Object(Vec3(800.0f, 400.0f, 0.0f), IMG_Load("Sprites/still.png"), 62, 28)*/ {
	vel = vel_;
	dir = Vec3(0.0f, 0.0f, 0.0f);
}
void Enemies::Damage(Player* player) {
	if (CollisionDetected(player) == true)
		player->health--;
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