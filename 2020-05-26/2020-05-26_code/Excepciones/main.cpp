#include <iostream>
#include <string>
#include "Exception.h"
#include "InvalidInput.h"

// void funcion() {
// 	try {
// 		std::cout << "No ha pasasado el throw" << std::endl;
// 		throw X();
// 		std::cout << "Ya pasó el throw" << std::endl;
// 	} catch (int ex) {
// 		std::cout << "Capturado un int: " << ex << std::endl;
// 	}
// }
// 
// void funcion2() {
// 	try {
// 		funcion();
// 	} catch (std::string ex) {
// 		std::cout << "Capturado un string: " << ex << std::endl;
// 	}
// }
// 
// void funcion3() {
// 	try {
// 		funcion2();
// 	} catch (Base ex) {
// 		std::cout << "Capturado una Base" << std::endl;
// 	}
// }
// 
// int main() {
// 	try {
// 		funcion3();
// 	} catch (...) {
// 		std::cout << "Unhandled Exception" << std::endl;
// 	}
// }

int foo(std::string x) {
	for (char c : x) {
		if (c >= 'a' || c <= 'z') {
			throw InvalidInput("Character is invalid");
		}
	}
	return std::stoi(x);
}

int main() {
	try {
		foo("123a");
	} catch (Exception ex) {
		std::cerr << ex.message() << std::endl;
	}
}
