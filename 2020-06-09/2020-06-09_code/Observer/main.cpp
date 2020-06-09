#include <iostream>
#include <Windows.h>
#include "ConcreteObserver.h"
#include "Subject.h"

int main() {
	setlocale(LC_ALL, "spanish");
	SetConsoleCP(1252);
	SetConsoleOutputCP(1252);
	std::cout << "Se ha inicializado el programa" << std::endl;
	ConcreteObserver* me = new ConcreteObserver("me");
	ConcreteObserver* tu = new ConcreteObserver("tu");
	ConcreteObserver* vous = new ConcreteObserver("vous");

	Subject* subject = new Subject("Joaquín");
	subject->addObserver(me);
	subject->addObserver(tu);
	subject->addObserver(vous);
	subject->setNombre("Pepín");
	subject->removeObserver(tu);
	subject->setNombre("Popón");
	std::cout << "Se ha terminado el programa" << std::endl;
}