#include "Scene2.h"
#include <SDL.h>

Scene2::Scene2(SDL_Window* sdlWindow_) {
	window = sdlWindow_;
	for (int i = 0; i < 5; i++)
	{
		enemies[i] = new Enemies(80.0f, spawner);
	}

}

Scene2::~Scene2() {
}

bool Scene2::OnCreate() {
	int w, h;
	SDL_GetWindowSize(window, &w, &h);
	Matrix4 ndc = MMath::viewportNDC(w, h);
	Matrix4 ortho = MMath::orthographic(0.0, 800.0, 0.0, 400.0, 0.0, 1.0);
	projection = ndc * ortho;
	player->image = IMG_Load("Sprites/player.png");
	player->sizeH = player->sizeW = 64;
	if (player == nullptr || player->image == nullptr) {
		return false;
	}
	return true;
}

void Scene2::OnDestroy() {}

void Scene2::Update(const float time) {
	player->Control();
	//player->Block(wall);
	player->Update(time);
	for (size_t i = 0; i < 5; i++)
	{
		if (enemies[i] != nullptr) {
			enemies[i]->Update(time);
			enemies[i]->AIChasing(player);
			if (enemies[i]->Damage(player)) {
				enemies[i] = nullptr;
				printf("%i", player->health);
			}
		}
	}
}

void Scene2::Render() {
	SDL_Surface* screenSurface = SDL_GetWindowSurface(window);
	SDL_FillRect(screenSurface, nullptr, SDL_MapRGB(screenSurface->format, 0xff, 0xff, 0xff));
	if (player->Death())
		gameOver->Render(window, projection);
	else
	{
		backGround->Render(window, projection);
		player->Render(window, projection);
		for (size_t i = 0; i < 5; i++)
		{
			if (enemies[i] != nullptr)
				enemies[i]->Render(window, projection);
		}
	}
	SDL_UpdateWindowSurface(window);
}
