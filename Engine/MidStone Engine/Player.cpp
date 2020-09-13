#include "Player.h"
Player::Player() {

}

Player::Player(Vec3 pos_, Vec3 vel_, Vec3 accel_, float mass_) {
	pos = pos_;
	vel = vel_;
	accel = accel_;
	mass = mass_;
}

Player::~Player() {

}

void Player::Update(const float deltaTime) {
	//printf("%f %f\n", pos.y, vel.y);
	pos.x += vel.x * deltaTime + 0.5f * accel.x * deltaTime * deltaTime;
	vel.x += accel.x * deltaTime;
	pos.y += vel.y * deltaTime + 0.5f * accel.y * deltaTime * deltaTime;
	vel.y += accel.y * deltaTime;
	pos.z += vel.z * deltaTime + 0.5f * accel.z * deltaTime * deltaTime;
	vel.z += accel.z * deltaTime;
}

void Player::ApplyForce(Vec3 force) {
	accel.x = force.x / mass;
	accel.y = force.y / mass;
	accel.z = force.z / mass;
}

Vec3 Player::GetPos() {
	return pos;
}