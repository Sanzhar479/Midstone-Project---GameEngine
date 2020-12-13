#pragma once
#include "Scene.h"
#include "MMath.h"
#include <SDL.h>
#include "Object.h"
class Scene1 :
    public Scene
{
private:
	Object* backGround = new Object(Vec3(0.0f, 0.0f, 0.0f), IMG_Load("Sprites/GameOver.png"), 0, 800);
	SDL_Window* window;
	Matrix4 projection;

public:
	Scene1(SDL_Window* sdlWindow);
	~Scene1();
	bool OnCreate();
	void OnDestroy();
	void Update(const float time);
	void Render();

};

