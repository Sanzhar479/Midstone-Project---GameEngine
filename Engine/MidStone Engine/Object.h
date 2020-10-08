#pragma once
#include "SDL.h"
#include "Vec2D.h"
class Object
{
	Vec2D pos;
	SDL_Surface* image;
	Object();
	//Here we can also assign image, collision, size of the object
	Object(Vec2D pos_, SDL_Surface* image_);
	~Object();
};

