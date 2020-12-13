#include "Player.h"
Player::Player() : Object() {
	//setting player as null
	vel = 0.0f;
	health = 0;
	score = 0;
	dir = Vec3(0.0f, 0.0f, 0.0f);
}
//setting player as object child class
//velocity, health, score that is needed to win; position, image, height, width
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
	//limits for the window
	//collision block
	if ((dir.x < 0 && pos.x <= 0) || (dir.x > 0 && pos.x >= 800 - sizeW) || (dir.y < 0 && pos.y - sizeH <= 0) || (dir.y > 0 && pos.y >= 400) || (blockedx == true)|| (blockedy == true))
		dir = Vec3(0.0f, 0.0f, 0.0f);
	//position update
	pos += dir * vel * deltaTime;
}
void Player::Control() {
	//if control key is pressed set direction to zero
	if (state[SDL_SCANCODE_LEFT] || state[SDL_SCANCODE_RIGHT] || state[SDL_SCANCODE_A] || state[SDL_SCANCODE_D] || state[SDL_SCANCODE_UP] || state[SDL_SCANCODE_DOWN] || state[SDL_SCANCODE_W] || state[SDL_SCANCODE_S]) {
		dir = Vec3(0.0f, 0.0f, 0.0f);
		//set direction x and then y
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
	//set direction to 0 if key was not pressed
	else dir = Vec3(0.0f, 0.0f, 0.0f);
}
void Player::Block(Object* object) {
	//checking if player is moveing torward the object if it's not then enable control
	//if not set direction to 0
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
	//if health is under 0 player is dead
	if (health < 0) 
		return true;
	return false;
}

