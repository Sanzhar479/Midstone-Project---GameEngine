#pragma once
#include <vector>
#include "Vector.h"
#include "VMath.h"
using namespace MATH;
class Spawner
{
public:
	Vec3 pos[6];
	Vec3 Rand();
	Spawner();
	Spawner(Vec3 pos_[]);
	~Spawner();
};

