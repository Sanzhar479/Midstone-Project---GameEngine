#include "Object.h"
Object::Object() {
	//if object is not initialised set it as null variable
	pos = Vec3();
	image = nullptr;
	sizeH = 0;
	sizeW = 0;
}
Object::Object(Vec3 pos_, SDL_Surface* image_, int sizeH_, int sizeW_) {
	//set all variables of the object
	sizeW = sizeW_;
	sizeH = sizeH_;
	pos.x = pos_.x;
	pos.y = pos_.y + sizeH;
	image = image_;
}
Object::~Object() {

}
void Object::Render(SDL_Window* window_, Matrix4 projection) {
	//creatinf the rect
	//setting position of the image
	SDL_Rect dst;
	Vec3 Pos = Vec3(projection * pos);
	//setting the size
	dst.w = sizeW;
	dst.h = sizeH;
	//converting float position to int
	dst.x = static_cast<int>(Pos.x);
	dst.y = static_cast<int>(Pos.y);
	SDL_Surface* screenSurface = SDL_GetWindowSurface(window_);
	//drawing image
	SDL_BlitSurface(image, nullptr, screenSurface, &dst);
}
bool Object::CollisionDetected(Object* object_) {
	//setting boarders of the image 
	//checking if distance between two objects is smaller then the size of the object
	if ((abs(pos.x - object_->pos.x) <= object_->sizeW) &&
		(abs(pos.y - object_->pos.y) <= object_->sizeH))
		return true;
	else return false;
}