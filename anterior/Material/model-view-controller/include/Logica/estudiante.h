#ifndef LOGICA_ESTUDIANTE_H
#define LOGICA_ESTUDIANTE_H

#include "persona.h"

namespace Logica {
    class Estudiante: public Persona {
        public:
            Estudiante() {
                Persona();
            }
            Estudiante(std::string id, std::string password, std::string nombre, bool activo) {
                Persona(id, password, nombre, activo);
            }
    };
}

#endif
