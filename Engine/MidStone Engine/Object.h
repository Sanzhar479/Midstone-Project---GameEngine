#pragma once
#include "SDL.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include "Vector.h"
#include "VMath.h"
#include <SDL.h>
#include "MMath.h"
#include <SDL_image.h>
using namespace MATH;
class Object
{
public:
	Vec3 pos;
	int sizeW, sizeH;
	SDL_Surface* image;
	void Render(SDL_Window* window_, Matrix4 projection);
	Object();
	Object(Vec3 pos_, SDL_Surface* image_, int sizeH_, int sizeW_);
	~Object();
	Vec3 GetPos();
	bool CollisionDetected(Object object_);
};

