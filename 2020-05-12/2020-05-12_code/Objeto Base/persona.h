#pragma once
#include <string>
#include <sstream>
#include "objetobase.h"
#include "linkedlist.h"
#include "curso.h"

class Curso;

class Persona : public ObjetoBase {
private:
	std::string id;
	std::string nombre;
	int edad;
	LinkedList* cursos_matriculados;
public:
	Persona() {
		this->id = "";
		this->nombre = "";
		this->edad = 0;
		this->cursos_matriculados = new LinkedList;
	}
	Persona(std::string id, std::string nombre, int edad) {
		this->id = id;
		this->nombre = nombre;
		this->edad = edad;
		this->cursos_matriculados = new LinkedList;
	}
	~Persona() {
		delete this->cursos_matriculados;
	}
	std::string getId() { return this->id; }
	std::string getNombre() { return this->nombre; }
	int getEdad() { return this->edad; }
	LinkedList* getCursosMatriculados() { return this->cursos_matriculados; }
	void setId(std::string id) { this->id = id; }
	void setNombre(std::string nombre) { this->nombre = nombre; }
	void setEdad(int edad) { this->edad = edad; }
	void addCursoMatriculado(ObjetoBase* curso) { this->cursos_matriculados->push(curso); }
	std::string toString() override {
		std::stringstream stream;
		stream << "Persona { " << std::endl;
		stream << "\tid: \"" << this->id << "\"" << std::endl;
		stream << "\tnombre: \"" << this->nombre << "\"" << std::endl;
		stream << "\tedad: \"" << this->edad << "\"" << std::endl;
		stream << "\tcursos matriculados: " << std::endl;
		Iterator* i;
		for (i = new Iterator(cursos_matriculados); !i->hasFinished(); i->goNext()) {
			stream << "\t\t" << i->getCurrent()->serialize() << std::endl;
		}
		delete i;
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
