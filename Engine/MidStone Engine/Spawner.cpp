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
	int num = rand() % 6;
	printf("%i\n", num);
	return pos[num];
}