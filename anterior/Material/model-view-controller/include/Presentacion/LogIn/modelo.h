#ifndef PRESENTACION_LOGIN_MODELO_H
#define PRESENTACION_LOGIN_MODELO_H

#include "../../Logica/persona.h"

namespace Presentacion {
    namespace Login {
        class Modelo {
            private:
                Logica::Persona* usuario;
            public:
                Modelo() {
                    this->usuario = nullptr;
                }
                Logica::Persona* getUsuario() { return this->usuario; }
                void setUsuario(Logica::Persona* usuario) { this->usuario = usuario; }
        };
    }
}

#endif
