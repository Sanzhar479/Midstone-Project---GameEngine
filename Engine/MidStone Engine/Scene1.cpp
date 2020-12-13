#include "Scene1.h"
#include <SDL.h>

Scene1::Scene1(SDL_Window* sdlWindow_) {
	window = sdlWindow_;
}

Scene1::~Scene1() {
}

bool Scene1::OnCreate() {
	int w, h;
	SDL_GetWindowSize(window, &w, &h);
	Matrix4 ndc = MMath::viewportNDC(w, h);
	Matrix4 ortho = MMath::orthographic(0.0, 800.0, 0.0, 400.0, 0.0, 1.0);
	projection = ndc * ortho;
	return true;
	if (backGround == nullptr || backGround->image == nullptr) {
		return false;
	}
}

void Scene1::OnDestroy() {}

void Scene1::Update(const float time) {
	printf("%f, %f\n", backGround->pos.x, backGround->pos.y);
}

void Scene1::Render() {
	SDL_Surface* screenSurface = SDL_GetWindowSurface(window);
	SDL_FillRect(screenSurface, nullptr, SDL_MapRGB(screenSurface->format, 0xff, 0xff, 0xff));
	backGround->Render(window, projection);
	SDL_UpdateWindowSurface(window);
}