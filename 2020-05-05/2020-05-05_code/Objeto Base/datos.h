#pragma once
#include <fstream>
#include "linkedlist.h"

class Datos {
private:
	LinkedList* estudiantes;
	LinkedList* cursos;
public:
	Datos() {
		this->estudiantes = new LinkedList();
		this->cursos = new LinkedList();
	}
	~Datos() {
		Iterator* i;
		for (i = new Iterator(estudiantes); !i->hasFinished(); i->goNext()) {
			delete i->getCurrent();
		}
		delete i;
		delete this->estudiantes;
		for (i = new Iterator(cursos); !i->hasFinished(); i->goNext()) {
			delete i->getCurrent();
		}
		delete i;
		delete this->cursos;
	}
	void readFile(std::string filename) {
		std::ifstream file(filename);
		std::string line;
		ObjetoBase* aux;
		while (std::getline(file, line, '\n')) {
			aux = generateObject(line);
			if (dynamic_cast<Persona*>(aux))
				estudiantes->push(aux);
			else if (dynamic_cast<Curso*>(aux))
				cursos->push(aux);
		}
	}
	ObjetoBase* generateObject(std::string line) {
		std::stringstream stream(line);
		std::string identifier;
		std::getline(stream, identifier, ':');
		std::string data;
		std::getline(stream, data);
		if (identifier == "P")
			return generatePersona(data);
		if (identifier == "C")
			return generateCurso(data);
		return nullptr;
	}
	Persona* generatePersona(std::string line) {
		std::stringstream stream(line);
		Persona* persona = new Persona();
		std::string aux;
		std::getline(stream, aux, ':');
		persona->setId(aux);
		std::getline(stream, aux, ':');
		persona->setNombre(aux);
		std::getline(stream, aux, ':');
		persona->setEdad(std::stoi(aux));
		return persona;
	}
	Curso* generateCurso(std::string line) {
		std::stringstream stream(line);
		Curso* curso = new Curso();
		std::string aux;
		std::getline(stream, aux, ':');
		curso->setId(aux);
		std::getline(stream, aux, ':');
		curso->setDescripcion(aux);
		std::getline(stream, aux, ':');
		curso->setLimiteEstudiantes(std::stoi(aux));
		return curso;
	}
	Persona* findPersona(std::string id) {
		Iterator* i;
		for (i = new Iterator(estudiantes); !i->hasFinished(); i->goNext()) {
			if (i->getCurrent() && i->getCurrent()->getIdentifier() == id && dynamic_cast<Persona*>(i->getCurrent()))
				return dynamic_cast<Persona*>(i->getCurrent());
		}
		delete i;
		return nullptr;
	}
	Curso* findCurso(std::string id) {
		Iterator* i;
		for (i = new Iterator(cursos); !i->hasFinished(); i->goNext()) {
			if (i->getCurrent() && i->getCurrent()->getIdentifier() == id && dynamic_cast<Curso*>(i->getCurrent()))
				return dynamic_cast<Curso*>(i->getCurrent());
		}
		delete i;
		return nullptr;
	}
	std::string toString() {
		std::stringstream s;
		Iterator* i;
		for (i = new Iterator(estudiantes); !i->hasFinished(); i->goNext()) {
			s << i->getCurrent()->serialize() << std::endl;
		}
		delete i;
		for (i = new Iterator(cursos); !i->hasFinished(); i->goNext()) {
			s << i->getCurrent()->serialize() << std::endl;
		}
		delete i;
		return s.str();
	}
};
