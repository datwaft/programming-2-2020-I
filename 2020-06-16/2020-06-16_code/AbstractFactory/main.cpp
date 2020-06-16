#include <iostream>
#include "Factory5.h"
#include "Product1.h"
#include "Product2.h"

int main() {
	AbstractFactory* factory = new Factory5();
	Figure* circle = factory->createProduct1();
	Figura* rectangle = factory->createProduct2();
	std::cout << "==============================================" << std::endl;
	std::cout << circle->toString() << std::endl;
	std::cout << "==============================================" << std::endl;
	std::cout << rectangle->toString() << std::endl;
	std::cout << "==============================================" << std::endl;
	delete factory;
}