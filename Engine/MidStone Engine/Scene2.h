#pragma once
#include "Scene.h"
#include "Spawner.h"
#include "Enemies.h"
#include "Player.h"
#include "MMath.h"
#include <SDL.h>

class Scene2 : public Scene {
private:
	//adding background and gameover screen
	Object* backGround = new Object(Vec3(0.0f, 0.0f, 0.0f), IMG_Load("Sprites/back.png"), 400, 800);
	Object* gameOver = new Object(Vec3(0.0f, 0.0f, 0.0f), IMG_Load("Sprites/GameOver.png"), 400, 800);
	//adding random spawner with default settings
	Spawner* spawner = new Spawner();
	//adding 5 enemies
	Enemies* enemies[5];
	SDL_Window* window;
	//velocity: 100, health: 3, score: 5
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

