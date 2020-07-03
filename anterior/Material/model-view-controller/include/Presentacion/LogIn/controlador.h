#ifndef PRESENTACION_LOGIN_CONTROLADOR_H
#define PRESENTACION_LOGIN_CONTROLADOR_H

#include "modelo.h"
#include "../../Logica/modelo.h"

namespace Presentacion {
    namespace Login {
        class Controlador {
            private:
                Modelo* modelo;
            public:
                Controlador(Modelo* modelo) {
                    this->modelo = modelo;
                }
                Modelo* getModelo() { return this->modelo; }
                void setModelo(Modelo* modelo) { this->modelo = modelo; }

                bool LogIn() {
                    Logica::Persona* user = Logica::Modelo::getInstance()->userExists(modelo->getUsuario());
                    if (user) {
                        Logica::Modelo::getInstance()->setUsuario(user);
                        return true;
                    }
                    else {
                        return false;
                    }
                }
        };
    }
}

#endif
