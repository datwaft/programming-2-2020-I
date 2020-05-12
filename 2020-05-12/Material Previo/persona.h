#pragma once
#include <string>
#include <sstream>
#include "objetobase.h"

class Persona : public ObjetoBase {
private:
	std::string id;
	std::string nombre;
	int edad;
public:
	Persona() {
		this->id = "";
		this->nombre = "";
		this->edad = 0;
	}
	Persona(std::string id, std::string nombre, int edad) {
		this->id = id;
		this->nombre = nombre;
		this->edad = edad;
	}
	std::string getId() { return this->id; }
	std::string getNombre() { return this->nombre; }
	int getEdad() { return this->edad; }
	void setId(std::string id) { this->id = id; }
	void setNombre(std::string nombre) { this->nombre = nombre; }
	void setEdad(int edad) { this->edad = edad; }
	std::string toString() override {
		std::stringstream stream;
		stream << "Persona { " << std::endl;
		stream << "\tid: \"" << this->id << "\"" << std::endl;
		stream << "\tnombre: \"" << this->nombre << "\"" << std::endl;
		stream << "\tedad: \"" << this->edad << "\"" << std::endl;
		stream << "}" << std::endl;
		return stream.str();
	}
	std::string serialize() override {
		std::stringstream stream;
		stream << "P:";
		stream << this->id << ":";
		stream << this->nombre << ":";
		stream << this->edad;
		return stream.str();
	}
	std::string getIdentifier() override {
		return this->id;
	}
};
