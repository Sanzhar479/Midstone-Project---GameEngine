#include "Spawner.h"
Spawner::Spawner() {
	for (size_t i = 0; i < sizeof(pos); i++)
		pos[i] = Vec3(900.0f, 500.0f, 0.0f);
}
Spawner::Spawner(Vec3 pos_[]) {
	for (size_t i = 0; i < sizeof(pos); i++)
		pos[i] = pos_[i];
}
Spawner::~Spawner() {

}
Vec3 Spawner::Rand() {
	int num = rand() % 0 + sizeof(pos);
	return pos[num];
}