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
	void readLinkFile(std::string filename) {
		std::ifstream file(filename);
		std::string line;
		while (std::getline(file, line, '\n')) {
			std::stringstream stream(line);
			std::string id1, id2;
			std::getline(stream, id1, ':');
			std::getline(stream, id2, ':');
			std::string data;
			std::getline(stream, data);
			if (id1 == "P" && id2 == "C") {
				try {
					linkPersonaCurso(data);
				}
				catch (std::runtime_error er) {
					continue;
				}
			}
		}
	}
	void linkPersonaCurso(std::string line) {
			std::stringstream stream(line);
			std::string persona_id, curso_id;
			std::getline(stream, persona_id, ':');
			std::getline(stream, curso_id, ':');
			Persona* persona = findPersona(persona_id);
			Curso* curso = findCurso(curso_id);
			if (!persona && !curso)
				throw std::runtime_error("Couldn't find neither the Persona nor the Curso");
			if (!persona)
				throw std::runtime_error("Couldn't find the Persona");
			if (!curso)
				throw std::runtime_error("Couldn't find the Curso");
			persona->addCursoMatriculado(curso);
			curso->addEstudianteMatriculado(persona);
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
			if (i->getCurrent() && i->getCurrent()->getIdentifier() == id && dynamic_cast<Persona*>(i->getCurrent())) {
				Persona* result = dynamic_cast<Persona*>(i->getCurrent());
				delete i;
				return result;
			}
		}
		delete i;
		return nullptr;
	}
	Curso* findCurso(std::string id) {
		Iterator* i;
		for (i = new Iterator(cursos); !i->hasFinished(); i->goNext()) {
			if (i->getCurrent() && i->getCurrent()->getIdentifier() == id && dynamic_cast<Curso*>(i->getCurrent())) {
				Curso* result = dynamic_cast<Curso*>(i->getCurrent());
				delete i;
				return result;
			}
		}
		delete i;
		return nullptr;
	}
	std::string toString() {
		std::stringstream s;
		Iterator* i;
		for (i = new Iterator(estudiantes); !i->hasFinished(); i->goNext()) {
			s << i->getCurrent()->toString() << std::endl;
		}
		delete i;
		for (i = new Iterator(cursos); !i->hasFinished(); i->goNext()) {
			s << i->getCurrent()->toString() << std::endl;
		}
		delete i;
		return s.str();
	}
};
