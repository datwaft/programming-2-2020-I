#include "Data.h"

int main() {
	std::cout << "Ha iniciado el programa" << std::endl;
	std::cout << Data::getInstance() << std::endl;
	for (auto x : Data::getInstance()->getNumeros())
		std::cout << x << ", ";
	std::cout << std::endl;
}