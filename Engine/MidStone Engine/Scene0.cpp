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
	player = new Player(50.0f);
	if (player == nullptr || player->image == nullptr) {
		return false;
	}
	return true;
}

void Scene0::OnDestroy() {}

void Scene0::Update(const float time) {
	player->Control(time);
}

void Scene0::Render() {
	SDL_Surface* screenSurface = SDL_GetWindowSurface(window);
	SDL_FillRect(screenSurface, nullptr, SDL_MapRGB(screenSurface->format, 0xff, 0xff, 0xff));
	player->Render(window, projection);
	SDL_UpdateWindowSurface(window);
}
