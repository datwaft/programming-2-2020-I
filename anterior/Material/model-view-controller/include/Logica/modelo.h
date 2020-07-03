#ifndef LOGICA_MODELO_H
#define LOGICA_MODELO_H

#include "persona.h"
#include "administrador.h"
#include "estudiante.h"
#include <vector>

namespace Logica {
    class Modelo {
        private:
            Modelo() {
                this->usuario = nullptr;
                usuarios.push_back(new Administrador("enabled", "pass", "Pepito", true));
                usuarios.push_back(new Administrador("disabled", "pass", "Adriano", false));
                usuarios.push_back(new Estudiante("student", "pass", "Francisco", true));
            }
            static Modelo* instance;
        public:
            static Modelo* getInstance() {
                if (!instance) {
                    instance = new Modelo();
                }
                return instance;
            }
            ~Modelo() {
                delete instance;
                delete usuario;
                for(int i =  0; i < usuarios.size(); ++i)
                    delete usuarios[i];
            }
        private:
            Persona* usuario;
            std::vector<Persona*> usuarios;
        public:
            Persona* getUsuario() { return this->usuario; }
            void setUsuario(Persona* usuario) { this->usuario = usuario; }
            Persona* userExists(Persona* usuario) {
                for(auto i : usuarios) {
                    if (usuario->getId() == i->getId()) {
                        if (usuario->getPassword() == i->getPassword()) {
                            return i;
                        }
                    }
                }
                return nullptr;
            }
    };
}

Logica::Modelo* Logica::Modelo::instance = nullptr;

#endif
