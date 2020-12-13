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
	//position of the object, size of the object and image
	Vec3 pos;
	int sizeW, sizeH;
	SDL_Surface* image;
	//drawing image on screan
	void Render(SDL_Window* window_, Matrix4 projection);
	Object();
	//easy initialisation of the object variable
	Object(Vec3 pos_, SDL_Surface* image_, int sizeH_, int sizeW_);
	~Object();
	//get position
	Vec3 GetPos();
	//detecting collision between objects
	bool CollisionDetected(Object* object_);
};

