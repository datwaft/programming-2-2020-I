#include <iostream>
#include "Circle.h"
#include "CircleCreator.h"

int main() {
	CircleCreator* creator = new CircleCreator(5);
	Circle* circle1 = creator->factoryMethod();
	Circle* circle2 = creator->factoryMethod();
	std::cout << circle1->toString() << std::endl;
	std::cout << circle2->toString() << std::endl;
	delete circle1;
	delete circle2;
	delete creator;
}