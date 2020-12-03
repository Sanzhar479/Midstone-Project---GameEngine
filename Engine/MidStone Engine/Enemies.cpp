#include "Enemies.h"
Enemies::Enemies() : Object() {
	vel = 0.0f;
	dir = Vec3(0.0f, 0.0f, 0.0f);
	spawner = new Spawner();
}
Enemies::Enemies(float vel_, Spawner* spawner_) : Object(spawner->Rand(), IMG_Load("Sprites/still.png"), 62, 28) {
	vel = vel_;
	spawner = spawner_;
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