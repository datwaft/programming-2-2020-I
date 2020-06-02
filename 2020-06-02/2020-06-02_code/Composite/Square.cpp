#include "Square.h"

Square::Square(unsigned int x, unsigned int y, double l) {
	this->x = x;
	this->y = y;
	this->l = l;
}

double Square::area() {
	return this->l * this->l;
}

double Square::perimetro() {
	return this->l * 4;
}
