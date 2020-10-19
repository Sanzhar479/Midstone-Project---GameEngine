#include "Scene0.h"
#include <SDL.h>
#include <SDL_image.h>
Scene0::Scene0(SDL_Window* sdlWindow_) {
	window = sdlWindow_;
}

Scene0::~Scene0() {
}

bool Scene0::OnCreate() {
	int w, h;
	SDL_GetWindowSize(window, &w, &h);
	player = new Player(Vec3(0.0f, 0.0f, 0.0f), 1.0f, IMG_Load("Sprites/still.png"), 10, 10);
	if (player == nullptr || player->image == nullptr) {
		return false;
	}
	return true;
}

void Scene0::OnDestroy() {}

void Scene0::Update(const float time) {
	player->Update(time);
}

void Scene0::Render() {
	SDL_Surface* screenSurface = SDL_GetWindowSurface(window);
	SDL_FillRect(screenSurface, nullptr, SDL_MapRGB(screenSurface->format, 0xff, 0xff, 0xff));
	player->Render(window);
	SDL_UpdateWindowSurface(window);
}
