#include "Subject.h"

std::string Subject::getNombre() const {
	return this->nombre;
}

void Subject::setNombre(std::string nombre) {
	if (this->nombre != nombre) {
		this->nombre = nombre;
		notify();
	}
}

Subject::Subject(std::string nombre) {
	setNombre(nombre);
}

Subject::~Subject() {
}

void Subject::addObserver(Observer* o) {
	this->observers.push_back(o);
}

void Subject::removeObserver(Observer* o) {
	std::remove_if(this->observers.begin(), this->observers.end(), [o](auto e) { return e == o;  });
}

void Subject::notify() {
	for (auto o : this->observers) {
		o->update(this);
	}
}
