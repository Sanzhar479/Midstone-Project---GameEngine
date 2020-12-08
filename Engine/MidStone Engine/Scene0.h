#pragma once
#include "Scene.h"
#include "Spawner.h"
#include "Enemies.h"
#include "Player.h"
#include "MMath.h"
#include <SDL.h>

class Scene0 : public Scene {
private:	
	Vec3 pos[6]{
		Vec3(-100.0f, -100.0f, 0.0f),
		Vec3(400.0f, -100.0f, 0.0f),
		Vec3(900.0f, -100.0f, 0.0f),
		Vec3(-100.0f, 500.0f, 0.0f),
		Vec3(400.0f, 500.0f, 0.0f),
		Vec3(900.0f, 500.0f, 0.0f)
	};
	Object* backGround = new Object(Vec3(0.0f, 0.0f, 0.0f), IMG_Load("Sprites/BackGround.png"), 400, 800);
	Spawner* spawner = new Spawner(pos);
	Enemies* enemies = new Enemies(20.0f);
	SDL_Window* window;
	Player* player = new Player(50.0f, 10);
	Matrix4 projection;

public:
	Scene0(SDL_Window* sdlWindow);
	~Scene0();
	bool OnCreate();
	void OnDestroy();
	void Update(const float time);
	void Render();

};