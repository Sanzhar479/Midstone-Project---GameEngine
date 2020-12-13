#pragma once
#include <vector>
#include "Vector.h"
#include "VMath.h"
#include <cstdlib>
#include <ctime>
#include <stdlib.h>
#include <time.h>
using namespace MATH;
using namespace std;
class Spawner
{
public:
	int lastNum[3] = { 0, 0 , 0 };
	Vec3 pos[6] = {
		Vec3(-100.0f, -100.0f, 0.0f),
		Vec3(400.0f, -100.0f, 0.0f),
		Vec3(900.0f, -100.0f, 0.0f),
		Vec3(-100.0f, 500.0f, 0.0f),
		Vec3(400.0f, 500.0f, 0.0f),
		Vec3(900.0f, 500.0f, 0.0f)
	};
	Vec3 Rand();
	Spawner();
	Spawner(Vec3 pos_[6]);
	~Spawner();
};

