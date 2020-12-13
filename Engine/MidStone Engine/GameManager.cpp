#include "GameManager.h"
#include "Window.h"
#include "Timer.h"
#include "Scene0.h"
#include "Scene1.h"
#include <SDL_image.h>
#include <iostream>

GameManager::GameManager() {
	timer = nullptr;
	isRunning = true;
	currentScene = nullptr;
	//mainScene = nullptr;
}


/// In this OnCreate() method, fuction, subroutine, whatever the word, 
bool GameManager::OnCreate() {
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		std::cout << "SDL_Error: " << SDL_GetError() << std::endl;
		OnDestroy();
		return false;
	}

	if (!IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG)) {
		std::cout << "SDL_Error: " << SDL_GetError() << std::endl;
		OnDestroy();
		return false;
	}

	const int SCREEN_WIDTH = 800;
	const int SCREEN_HEIGHT = 400;
	ptr = new Window(SCREEN_WIDTH, SCREEN_HEIGHT);

	if (ptr == nullptr) {
		OnDestroy();
		return false;
	}
	if (ptr->OnCreate() == false) {
		OnDestroy();
		return false;
	}

	timer = new Timer();
	if (timer == nullptr) {
		OnDestroy();
		return false;
	}

	//switching scenes
	currentScene = new Scene0(ptr->GetSDL_Window());
	//currentScene = new Scene2(ptr->GetSDL_Window());
	if (currentScene == nullptr) {
		OnDestroy();
		return false;
	}

	if (currentScene->OnCreate() == false) {
		OnDestroy();
		return false;
	}

	return true;
}

/// Here's the whole game
void GameManager::Run() {
	timer->Start();
	SDL_Event sdlEvent;
	SDL_Event e;

	while (isRunning) {
		/*while (SDL_PollEvent(&sdlEvent)) {
			if (sdlEvent.type == SDL_QUIT) {
				isRunning = false;
			}
		}*/ 
		
		HandleEvents(sdlEvent);
		SDL_PollEvent(&e);
		if (e.type == SDL_QUIT) {
			break;
		}
		timer->UpdateFrameTicks();
		currentScene->Update(timer->GetDeltaTime());
		currentScene->Render();

		/// Keeep the event loop running at a proper rate
		SDL_Delay(timer->GetSleepTime(60)); ///60 frames per sec
	}
}
void GameManager::HandleEvents(SDL_Event& sdlEvent) {
	while (SDL_PollEvent(&sdlEvent)) {
		if (sdlEvent.type == SDL_QUIT) {
			isRunning = false;
		}
	}
}


GameManager::~GameManager() {}

void GameManager::OnDestroy() {
	if (ptr) delete ptr;
	if (timer) delete timer;
	if (currentScene) delete currentScene;
	///Exit the SDL subsystems
	SDL_Quit();
	IMG_Quit();
}