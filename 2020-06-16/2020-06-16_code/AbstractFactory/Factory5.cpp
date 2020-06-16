#include "Factory5.h"

Factory5::Factory5() {
}

Factory5::~Factory5() {
}

Figure* Factory5::createProduct1() {
	return new Circle(5);
}

Figura* Factory5::createProduct2() {
	return new Rectangle(5, 5);
}
