#pragma once
#include "SDL.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include "Vector.h"
#include "VMath.h"
using namespace MATH;
class Object
{
public:
	Vec3 pos;
	SDL_Surface* image;
	int sizeW, sizeH;
	void Render(SDL_Window* window_);
	Object();
	Object(Vec3 pos_, SDL_Surface* image_, int sizeW_, int sizeH_);
	~Object();
	Vec3 GetPos();
};

