#pragma once
#include "Scene.h"
#include "Spawner.h"
#include "Enemies.h"
#include "Player.h"
#include "MMath.h"
#include <SDL.h>

class Scene2 : public Scene {
private:
	Object* backGround = new Object(Vec3(0.0f, 0.0f, 0.0f), IMG_Load("Sprites/back.png"), 400, 800);
	Object* gameOver = new Object(Vec3(0.0f, 0.0f, 0.0f), IMG_Load("Sprites/GameOver.png"), 400, 800);
	//Object* wall = new Object(Vec3(0.0f, 250.0f, 0.0f), NULL, 150, 800);
	Spawner* spawner = new Spawner();
	Enemies* enemies[5];
	SDL_Window* window;
	Player* player = new Player(100.0f, 3, 5);
	Matrix4 projection;

public:
	Scene2(SDL_Window* sdlWindow);
	~Scene2();
	bool OnCreate();
	void OnDestroy();
	void Update(const float time);
	void Render();
};

