#include "Data.h"

Data* Data::instance = nullptr;

Data::Data() {
	// Inicializamos los numeros
	this->numeros.push_back(20);
	this->numeros.push_back(22);
	this->numeros.push_back(32);
	this->numeros.push_back(53);
}

std::vector<int> Data::getNumeros() const {
	return this->numeros;
}

Data::~Data() {
	Data::instance = nullptr;
}

Data* Data::getInstance() {
	if (!Data::instance) {
		Data::instance = new Data();
	}
	return Data::instance;
}
