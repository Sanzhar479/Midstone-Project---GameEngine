#include "Player.h"
Player::Player() {
	pos = Vec3();
	vel = 0.0f;
	image = NULL;
	dir() = Vec3();
}

Player::Player(Vec3 pos_, float vel_, SDL_Surface* image_) {
	pos = pos_;
	vel = vel_;
	dir() = Vec3();
	image = image_;
}

Player::~Player() {

}
//movement
void Player::Update(const float deltaTime) {
	pos += dir() * vel * deltaTime;
	printf("\n%f %f %f %f", pos.x, pos.y, dir().x, dir().y);
}
//drawing an image on screen
void Player::Render(SDL_Window* window_) {
	SDL_Rect dst;
	dst.x = static_cast<int>(pos.x);
	dst.y = static_cast<int>(pos.y);
	SDL_Surface* screenSurface = SDL_GetWindowSurface(window_);
	SDL_BlitSurface(image, nullptr, screenSurface, &dst);
}
//direction of the player to use it in movement and animation
Vec3 Player::dir() {
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
		return Vec3(xdir, ydir, 0.0f);
	}
	else
		return Vec3(xdir, ydir, 0.0f);
}