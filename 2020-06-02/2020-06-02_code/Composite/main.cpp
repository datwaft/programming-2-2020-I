#include <iostream>
#include "Composite.h"
#include "Square.h"

int main() {
	Square* s1 = new Square(1, 3, 2); 
	Square* s2 = new Square(2, 4, 1); 
	Composite* composite = new Composite();
	composite->add(s1);
	composite->add(s2);

	std::cout << "s1 area: " << s1->area() << std::endl;
	std::cout << "s2 area: " << s2->area() << std::endl;
	std::cout << "composite area: " << composite->area() << std::endl;
}