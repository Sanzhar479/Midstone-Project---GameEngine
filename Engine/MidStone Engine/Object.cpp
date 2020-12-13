#include "Object.h"
Object::Object() {
	pos = Vec3();
	image = nullptr;
	sizeH = 0;
	sizeW = 0;
}
Object::Object(Vec3 pos_, SDL_Surface* image_, int sizeH_, int sizeW_) {
	sizeW = sizeW_;
	sizeH = sizeH_;
	pos.x = pos_.x;
	pos.y = pos_.y + sizeH;
	image = image_;
}
Object::~Object() {

}
void Object::Render(SDL_Window* window_, Matrix4 projection) {
	SDL_Rect dst;
	Vec3 Pos = Vec3(projection * pos);
	dst.w = sizeW;
	dst.h = sizeH;
	dst.x = static_cast<int>(Pos.x);
	dst.y = static_cast<int>(Pos.y);
	SDL_Surface* screenSurface = SDL_GetWindowSurface(window_);
	SDL_BlitSurface(image, nullptr, screenSurface, &dst);
}
bool Object::CollisionDetected(Object* object_) {
	if ((abs(pos.x - object_->pos.x) < sizeW + object_->sizeW) &&
		(abs(pos.y - object_->pos.y) < sizeH + object_->sizeH))
		return true;
	else return false;
}