#include <iostream>
#include "Rectangle.h"
#include "Red.h"
#include "Blue.h"

int main() {
	Color* red = new Red();
	Color* blue = new Blue();
	Rectangle* redrect = new Rectangle(1, 1, red);
	Rectangle* bluerect = new Rectangle(5, 5, blue);
	Rectangle* rect = new Rectangle(2, 2);
	std::cout << "==============================================" << std::endl;
	std::cout << redrect->toString() << std::endl;
	std::cout << "==============================================" << std::endl;
	std::cout << bluerect->toString() << std::endl;
	std::cout << "==============================================" << std::endl;
	std::cout << rect->toString() << std::endl;
	std::cout << "==============================================" << std::endl;
}