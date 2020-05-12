#pragma once
#include <string>
#include <sstream>
#include "objetobase.h"
#include "linkedlist.h"
#include "persona.h"

class Persona;

class Curso : public ObjetoBase {
private:
	std::string id;
	std::string descripcion;
	int limite_estudiantes;
	LinkedList* estudiantes_matriculados;
public:
	Curso() {
		this->id = "";
		this->descripcion = "";
		this->limite_estudiantes = 0;
		this->estudiantes_matriculados = new LinkedList;
	}
	Curso(std::string id, std::string descripcion, int limite_estudiantes) {
		this->id = id;
		this->descripcion = descripcion;
		this->limite_estudiantes = limite_estudiantes;
		this->estudiantes_matriculados = new LinkedList;
	}
	~Curso() {
		delete this->estudiantes_matriculados;
	}
	std::string getId() { return this->id; }
	std::string getDescripcion() { return this->descripcion; }
	int getLimiteEstudiantes() { return this->limite_estudiantes; }
	LinkedList* getEstudiantesMatriculados() { return this->estudiantes_matriculados; }
	void setId(std::string id) { this->id = id; }
	void setDescripcion(std::string descripcion) { this->descripcion = descripcion; }
	void setLimiteEstudiantes(int limite_estudiantes) { this->limite_estudiantes = limite_estudiantes; }
	void addEstudianteMatriculado(ObjetoBase* persona) { this->estudiantes_matriculados->push(persona); }
	std::string toString() override {
		std::stringstream stream;
		stream << "Curso {" << std::endl;
		stream << "\tid: \"" << this->id << "\"" << std::endl;
		stream << "\tdescripcion: \"" << this->descripcion << "\"" << std::endl;
		stream << "\tlimite_estudiantes: \"" << this->limite_estudiantes << "\"" << std::endl;
		stream << "\testudiantes matriculados: " << std::endl;
		Iterator* i;
		for (i = new Iterator(estudiantes_matriculados); !i->hasFinished(); i->goNext()) {
			stream << "\t\t" << i->getCurrent()->serialize() << std::endl;
		}
		delete i;
		stream << "}" << std::endl;
		return stream.str();
	}
	std::string serialize() override {
		std::stringstream stream;
		stream << "C:";
		stream << this->id << ":";
		stream << this->descripcion << ":";
		stream << this->limite_estudiantes;
		return stream.str();
	}
	std::string getIdentifier() override {
		return this->id;
	}
};
