#pragma once
#include "Scene.h"
#include "Player.h"
#include "MMath.h"
#include <SDL.h>

class Scene0 : public Scene {
private:
	SDL_Window* window;
	Player* player;
	Matrix4 projection;
public:
	Scene0(SDL_Window* sdlWindow);
	~Scene0();
	bool OnCreate();
	void OnDestroy();
	void Update(const float time);
	void Render();

};