#pragma once
#include "Scene.h"
#include "Spawner.h"
#include "Enemies.h"
#include "Player.h"
#include "MMath.h"
#include <SDL.h>

class Scene0 : public Scene {
private:	
	//setting background
	Object* backGround = new Object(Vec3(0.0f, 0.0f, 0.0f), IMG_Load("Sprites/BackGround.png"), 400, 800);
	//setting collision block wall
	Object* wall = new Object(Vec3(0.0f, 250.0f, 0.0f), NULL, 150, 800);
	SDL_Window* window;
	//velocity: 80, health: 3, score: 5
	Player* player = new Player(80.0f, 3, 5);
	Matrix4 projection;

public:
	Scene0(SDL_Window* sdlWindow);
	~Scene0();
	bool OnCreate();
	void OnDestroy();
	void Update(const float time);
	void Render();
	bool dead = false;
};