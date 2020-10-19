#include "Object.h"
Object::Object() {
	pos = Vec3();
	image = nullptr;
	sizeH = 0;
	sizeW = 0;
}
Object::Object(Vec3 pos_, SDL_Surface* image_, int sizeW_, int sizeH_) {
	pos = pos_;
	image = image_;
}
Object::~Object() {

}
void Object::Render(SDL_Window* window_) {
	SDL_Rect dst;
	dst.w = sizeW;
	dst.h = sizeH;
	dst.x = static_cast<int>(pos.x);
	dst.y = static_cast<int>(pos.y);
	SDL_Surface* screenSurface = SDL_GetWindowSurface(window_);
	SDL_BlitSurface(image, nullptr, screenSurface, &dst);
}