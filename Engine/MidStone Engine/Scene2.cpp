#include "Scene2.h"
#include <SDL.h>

Scene2::Scene2(SDL_Window* sdlWindow_) {
	window = sdlWindow_;
	//setting each enemies' velocity and position from spawner(random)
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
	//setting new player image
	player->image = IMG_Load("Sprites/player.png");
	//setting new size of the player
	player->sizeH = player->sizeW = 64;
	if (player == nullptr || player->image == nullptr) {
		return false;
	}
	return true;
}

void Scene2::OnDestroy() {}

void Scene2::Update(const float time) {
	//setting player control
	player->Control();
	player->Update(time);
	//updating all enemies
	for (size_t i = 0; i < 5; i++)
	{
		//if enemy was not deleted run this code
		if (enemies[i] != nullptr) {
			//update position and find the direction of the enemy
			enemies[i]->Update(time);
			enemies[i]->AIChasing(player);
			//if player took damage destroy enemy and take of one point of health and print updated health
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
	//render gameover screen if player is dead
	if (player->Death())
		gameOver->Render(window, projection);
	else
	{
		//render background, player and all alive enemies
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
