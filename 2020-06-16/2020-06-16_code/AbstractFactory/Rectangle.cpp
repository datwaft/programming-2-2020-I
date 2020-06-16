#include "Rectangle.h"

std::string Rectangle::getLine(bool external)
{
	if (width == 1)
		return (external ? "+" : "|" );
	std::stringstream s;
	s << (external ? "+" : "|" );
	for (int i = 1; i < width - 1; ++i) {
		s << (external ? "-" : " ");
	}
	s << (external ? "+" : "|" );
	return s.str();
}

Rectangle::Rectangle(int height, int width) {
	this->height = height;
	this->width = width;
}

Rectangle::~Rectangle() {
}

std::string Rectangle::toString() {
	if (height == 1)
		return this->getLine();
	std::stringstream s;
	s << this->getLine() << std::endl;
	for (int i = 1; i < height - 1; ++i) {
		s << this->getLine(false) << std::endl;
	}
	s << this->getLine();
	return s.str();
}
