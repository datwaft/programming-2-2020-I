#include "CircleCreator.h"

CircleCreator::CircleCreator(int r) {
	this->radius = r;
}

CircleCreator::~CircleCreator() {
}

Circle* CircleCreator::factoryMethod() {
	return new Circle(this->radius);
}
