#include "Player.h"
Player::Player() {
	position.Zero();
}



Player::~Player() {

}

void Player::PlayerStats(float x, float y, int h, int w, int sc)
{
	position.x = x;
	position.y = y;
	height = h;
	width = w;
	scale = sc;
}

