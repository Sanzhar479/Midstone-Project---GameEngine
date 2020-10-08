#include "Object.h"
Object::Object() {
	pos = Vec2D();
}
Object::Object(Vec2D pos_, SDL_Surface* image_) {
	pos = pos_;
	image = image_;
}
Object::~Object() {

}
