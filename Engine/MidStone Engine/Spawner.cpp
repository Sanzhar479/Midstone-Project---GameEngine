#include "Spawner.h"

Spawner::Spawner() {
}
Spawner::Spawner(Vec3 pos_[6]) {
	//setting new spawn points
	for (size_t i = 0; i < 6; i++)
		pos[i] = pos_[i];
}
Spawner::~Spawner() {

}
Vec3 Spawner::Rand() {
	//setting randomizer
	srand(time(NULL));
	//set number of the array member
	int num = 0;
	//checking if current number isn't equal the previous random numbers
	while (num == lastNum[0] || num == lastNum[1] || num == lastNum[2])
	//randomizer itself
	num = rand() % 6;
	//updating previous numbers
	lastNum[2] = lastNum[1];
	lastNum[1] = lastNum[0];
	lastNum[0] = num;
	//return random position
	return pos[num];
}