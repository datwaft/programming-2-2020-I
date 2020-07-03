#ifndef LOGICA_PROFESOR_H
#define LOGICA_PROFESOR_H

#include "persona.h"

namespace Logica {
    class Profesor: public Persona {
        public:
            Profesor() {
                Persona();
            }
            Profesor(std::string id, std::string password, std::string nombre, bool activo) {
                Persona(id, password, nombre, activo);
            }
    };
}

#endif
