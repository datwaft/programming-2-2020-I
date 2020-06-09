#include "ConcreteObserver.h"

ConcreteObserver::ConcreteObserver(std::string nombre) {
	this->nombre = nombre;
}

ConcreteObserver::~ConcreteObserver() {
}

void ConcreteObserver::update(Subject* subject) {
	std::cout << this->nombre << " ha sido notificado :D (Ha cumplido su propósito)." << std::endl;
	std::cout << "El nuevo nombre es: " << subject->getNombre() << std::endl;
}
