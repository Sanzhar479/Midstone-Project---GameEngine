#include "Player.h"
Player::Player() {
	pos = Vec2D();
	vel = 0.0f;
}

Player::Player(Vec2D pos_, float vel_) {
	pos = pos_;
	vel = vel_;
	dir() = Vec2D();
}

Player::~Player() {

}

void Player::Update(const float deltaTime) {
	pos += dir() * vel * deltaTime;
	printf("\n%f %f %f %f", pos.x, pos.y, dir().x, dir().y);
}

Vec2D Player::dir() {
	if (state[SDL_SCANCODE_LEFT] || state[SDL_SCANCODE_RIGHT] || state[SDL_SCANCODE_UP] || state[SDL_SCANCODE_DOWN]) {
		xdir = 0.0f;
		ydir = 0.0f;
		if (state[SDL_SCANCODE_LEFT])
			xdir = -1.0f;
		else
			if (state[SDL_SCANCODE_RIGHT])
				xdir = 1.0f;
		if (state[SDL_SCANCODE_UP])
			ydir = 1.0f;
		else
			if (state[SDL_SCANCODE_DOWN])
				ydir = -1.0f;
		return Vec2D(xdir, ydir).Normalise();
	}
	else
		return Vec2D(xdir, ydir).Normalise();
}

Vec2D Player::GetPos() {
	return pos;
}