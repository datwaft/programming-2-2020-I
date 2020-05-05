#include <exception>
#include <iostream>
#include "persona.h"
#include "curso.h"
#include "datos.h"

int main() {
	try {
		Datos* data = new Datos();
		data->readFile("../personas.txt");
		data->readFile("../cursos.txt");
		std::cout << data->toString() << std::endl;
		std::cout << data->findPersona("12")->toString() << std::endl;
		delete data;
	} catch (std::exception ex) {
		std::cerr << "Uncaught exception: " << ex.what() << std::endl;
	} catch (...) {
		std::cerr << "Unexpected exception" << std::endl;
	}
}