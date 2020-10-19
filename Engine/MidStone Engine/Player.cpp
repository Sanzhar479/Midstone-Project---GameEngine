#include "Player.h"
Player::Player() {
	pos = Vec3(0.0f, 0.0f, 0.0f);
	vel = 0.0f;
	image = NULL;
}

Player::Player(Vec3 pos_, float vel_, SDL_Surface* image_, int sizeH_, int sizeW_) {
	pos = pos_;
	vel = vel_;
	image = image_;
	sizeH = 0;
	sizeW = 0;
}

Player::~Player() {

}
//movement
void Player::Update(const float deltaTime) {
	if (state[SDL_SCANCODE_LEFT] || state[SDL_SCANCODE_RIGHT] || state[SDL_SCANCODE_UP] || state[SDL_SCANCODE_DOWN]) {
		dir = Vec3(0.0f, 0.0f, 0.0f);
		if (state[SDL_SCANCODE_LEFT])
			dir.x = -1.0f;
		else
			if (state[SDL_SCANCODE_RIGHT])
				dir.x = 1.0f;
		if (state[SDL_SCANCODE_UP])
			dir.y = 1.0f;
		else
			if (state[SDL_SCANCODE_DOWN])
				dir.y = -1.0f;
	}
	pos += dir * vel * deltaTime;
	printf("\n%f %f %f %f", pos.x, pos.y, dir.x, dir.y);
}
//drawing an image on screen
void Player::Render(SDL_Window* window_) {
	SDL_Rect dst;
	dst.w = sizeW;
	dst.h = sizeH;
	dst.x = static_cast<int>(pos.x);
	dst.y = static_cast<int>(pos.y);
	SDL_Surface* screenSurface = SDL_GetWindowSurface(window_);
	SDL_BlitSurface(image, nullptr, screenSurface, &dst);
}
//direction of the player to use it in movement and animation
bool Player::CollisionDetected(Object object_) {
	if ((pos.x < object_.pos.x + object_.sizeW) &&
		(pos.x + sizeW > object_.pos.x) &&
		(pos.y < object_.pos.y + object_.sizeH) &&
		(pos.y + sizeH > object_.pos.y))
		return true;
	else return false;
}