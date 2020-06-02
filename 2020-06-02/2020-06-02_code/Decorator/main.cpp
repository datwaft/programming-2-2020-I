#include "Double.h"
#include "Sumar.h"
#include <iostream>

int main() {
	Component* sumar = new Sumar();
	Component* d2 = new Double(sumar);
	Component* d4 = new Double(d2);

	int a = 3;
	int b = 7;

	std::cout << "Suma de a y b: ";
	std::cout << sumar->operation(a, b) << std::endl;
	std::cout << "Suma de a y b multiplicada por 2: ";
	std::cout << d2->operation(a, b) << std::endl;
	std::cout << "Suma de a y b D4: ";
	std::cout << d4->operation(a, b) << std::endl;
}