#include "Scene0.h"
#include <SDL.h>

Scene0::Scene0(SDL_Window* sdlWindow_) {
	window = sdlWindow_;
}

Scene0::~Scene0() {
}

bool Scene0::OnCreate() {
	int w, h;
	SDL_GetWindowSize(window, &w, &h);
	Matrix4 ndc = MMath::viewportNDC(w, h);
	Matrix4 ortho = MMath::orthographic(0.0, 800.0, 0.0, 400.0, 0.0, 1.0);
	projection = ndc * ortho;
	pos[0] = Vec3(-100.0f, -100.0f, 0.0f);
	pos[1] = Vec3(400.0f, -100.0f, 0.0f);
	pos[2] = Vec3(900.0f, -100.0f, 0.0f);
	pos[3] = Vec3(-100.0f, 500.0f, 0.0f);
	pos[4] = Vec3(400.0f, 500.0f, 0.0f);
	pos[5] = Vec3(900.0f, 500.0f, 0.0f);
	player = new Player(50.0f, 10);
	spawner = new Spawner(pos);
	enemies = new Enemies(50.0f, spawner);
	if (player == nullptr || player->image == nullptr) {
		return false;
	}
	return true;
}

void Scene0::OnDestroy() {}

void Scene0::Update(const float time) {
	player->Control(time);
	enemies->AIChasing(player);
	enemies->Update(time);
	spawner->Rand();
}

void Scene0::Render() {
	SDL_Surface* screenSurface = SDL_GetWindowSurface(window);
	SDL_FillRect(screenSurface, nullptr, SDL_MapRGB(screenSurface->format, 0xff, 0xff, 0xff));
	player->Render(window, projection);
	SDL_UpdateWindowSurface(window);
}
