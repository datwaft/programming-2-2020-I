#ifndef LOGICA_ADMINISTRADOR_H
#define LOGICA_ADMINISTRADOR_H

#include "persona.h"

namespace Logica {
    class Administrador: public Persona {
        public:
            Administrador() {
                Persona();
            }
            Administrador(std::string id, std::string password, std::string nombre, bool activo) {
                Persona(id, password, nombre, activo);
            }
    };
}

#endif
