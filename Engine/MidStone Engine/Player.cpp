#include "Player.h"
Player::Player() : Object() {
	vel = 0.0f;
	health = 0;
	dir = Vec3(0.0f, 0.0f, 0.0f);
}

Player::Player(float vel_, int health_) : Object(Vec3(0.0f, 0.0f, 0.0f), IMG_Load("Sprites/still.png"), 62, 28) {
	vel = vel_;
	dir = Vec3(0.0f, 0.0f, 0.0f);
	health = health_;
}

Player::~Player() {

}
//movement
void Player::Update(const float deltaTime) {
	pos += dir * vel * deltaTime;
	printf("\n%f %f %f %f", pos.x, pos.y, dir.x, dir.y);
}
void Player::Control(const float deltaTime) {
	if (state[SDL_SCANCODE_LEFT] || state[SDL_SCANCODE_RIGHT] || state[SDL_SCANCODE_UP] || state[SDL_SCANCODE_DOWN] || 
		state[SDL_SCANCODE_A] || state[SDL_SCANCODE_D] || state[SDL_SCANCODE_W] || state[SDL_SCANCODE_S]) {
		dir = Vec3(0.0f, 0.0f, 0.0f);
		if (state[SDL_SCANCODE_RIGHT] || state[SDL_SCANCODE_D]) {
			dir.x = 1.0f;
		}
		else
			if (state[SDL_SCANCODE_LEFT] || state[SDL_SCANCODE_A]) {
				dir.x = -1.0f;
			}
		if (state[SDL_SCANCODE_UP] || state[SDL_SCANCODE_W]) {
			dir.y = 1.0f;
		}
		else
			if (state[SDL_SCANCODE_DOWN] || state[SDL_SCANCODE_S]) {
				dir.y = -1.0f;
			}
	}
	Update(deltaTime);
}
void Player::Block(Object* object) {
	if (CollisionDetected(object) == true) {
		if ((dir.x > 0 && pos.x + sizeW >= object->pos.x) || (dir.x < 0 && pos.x <= object->pos.x + object->sizeW))
			dir.x = 0;
		if ((dir.y > 0 && pos.y >= object->pos.y - object->sizeH) || (dir.y < 0 && pos.y - sizeH <= object->pos.y))
			dir.y = 0;
	}
}

void Player::Death(Player* player) {
	if (health <= 0)
		player;
}

