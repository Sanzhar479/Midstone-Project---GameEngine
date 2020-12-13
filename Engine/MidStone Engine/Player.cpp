#include "Player.h"
Player::Player() : Object() {
	vel = 0.0f;
	health = 0;
	score = 0;
	dir = Vec3(0.0f, 0.0f, 0.0f);
}

Player::Player(float vel_, int health_, int score_) : Object(Vec3(0.0f, 0.0f, 0.0f), IMG_Load("Sprites/still.png"), 62, 28) {
	vel = vel_;
	dir = Vec3(0.0f, 0.0f, 0.0f);
	health = health_;
	score = score_;
}

Player::~Player() {

}
//movement
void Player::Update(const float deltaTime) {
	if ((dir.x < 0 && pos.x <= 0) || (dir.x > 0 && pos.x >= 800 - sizeW) || (dir.y < 0 && pos.y - sizeH <= 0) || (dir.y > 0 && pos.y >= 400) || (blockedx == true)|| (blockedy == true))
		dir = Vec3(0.0f, 0.0f, 0.0f);
	pos += dir * vel * deltaTime;
}
void Player::Control() {
	if (state[SDL_SCANCODE_LEFT] || state[SDL_SCANCODE_RIGHT] || state[SDL_SCANCODE_A] || state[SDL_SCANCODE_D] || state[SDL_SCANCODE_UP] || state[SDL_SCANCODE_DOWN] || state[SDL_SCANCODE_W] || state[SDL_SCANCODE_S]) {
		dir = Vec3(0.0f, 0.0f, 0.0f);
		if ((state[SDL_SCANCODE_RIGHT] || state[SDL_SCANCODE_D])) {
			dir.x = 1.0f;
		}
		else
			if ((state[SDL_SCANCODE_LEFT] || state[SDL_SCANCODE_A])) {
				dir.x = -1.0f;
			}
		if ((state[SDL_SCANCODE_UP] || state[SDL_SCANCODE_W])) {
			dir.y = 1.0f;
		}
		else
			if ((state[SDL_SCANCODE_DOWN] || state[SDL_SCANCODE_S])) {
				dir.y = -1.0f;
			}
	}
	else dir = Vec3(0.0f, 0.0f, 0.0f);
}
void Player::Block(Object* object) {
	if ((CollisionDetected(object) == true) && ((dir.x > 0.0f && pos.x >= object->pos.x - sizeW && pos.x <= object->pos.x) || (dir.x < 0.0f && pos.x <= object->pos.x - sizeW && pos.x >= object->pos.x)))
		blockedx = true;
	else blockedx = false;
	if ((CollisionDetected(object) == true) && ((dir.y > 0.0f && pos.y >= object->pos.y - object->sizeH && pos.y <= object->pos.y) || (dir.y < 0.0f && pos.y <= object->pos.y - sizeH && pos.y >= object->pos.y))) {
		blockedy = true;
		printf("c");
	}
	else blockedy = false;
}

bool Player::Death() {
	if (health < 0) {
		pos = Vec3(-1000.0f, -1000.0f, 0.0f);
		return true;
	}
	return false;
}

