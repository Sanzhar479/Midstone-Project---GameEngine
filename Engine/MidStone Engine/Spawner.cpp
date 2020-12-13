#include "Spawner.h"

Spawner::Spawner() {
}
Spawner::Spawner(Vec3 pos_[6]) {
	for (size_t i = 0; i < 6; i++)
		pos[i] = pos_[i];
}
Spawner::~Spawner() {

}
Vec3 Spawner::Rand() {
	srand(time(NULL));
	int num = 0;
	while (num == lastNum[0] || num == lastNum[1] || num == lastNum[2])
	num = rand() % 6;
	lastNum[2] = lastNum[1];
	lastNum[1] = lastNum[0];
	lastNum[0] = num;
	return pos[num];
}