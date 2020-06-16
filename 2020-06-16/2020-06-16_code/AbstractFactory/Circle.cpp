#include "Circle.h"

Circle::Circle(int radius) {
	this->radius = radius;
}

Circle::~Circle() {
}

std::string Circle::getLine(int h) {
	int height = abs(h);
	if (height == this->radius)
		return std::string(this->radius, ' ') + "*";
	std::stringstream s;
	for (int i = 0; i < height; ++i) {
		s << " ";
	}
	s << "*";
	for (int i = 1; i < this->radius - height; ++i) {
		s << " ";
	}
	s << " ";
	for (int i = 1; i < this->radius - height; ++i) {
		s << " ";
	}
	s << "*";
	return s.str();
}

std::string Circle::toString() {
	std::stringstream s;
	for (int i = -this->radius; i <= this->radius; ++i) {
		s << getLine(i) << std::endl;
	}
	return s.str();
}
