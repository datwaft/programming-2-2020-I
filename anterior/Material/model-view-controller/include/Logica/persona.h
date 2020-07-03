#ifndef LOGICA_PERSONA_H
#define LOGICA_PERSONA_H

#include <string>

namespace Logica {
    class Persona {
        private:
            std::string id;
            std::string password;
            std::string nombre;
            bool activo;
        public:
            Persona() {
                this->id = "";
                this->password = "";
                this->nombre = "";
                this->activo = "";
            }
            Persona(std::string id, std::string password, std::string nombre, bool activo) {
                this->id = id;
                this->password = password;
                this->nombre = nombre;
                this->activo = activo;
            }
            std::string getId() { return this->id; }
            std::string getPassword() { return this->password; }
            std::string getNombre() { return this->nombre; }
            bool getActivo() { return this->activo; }
            void setId(std::string id) { this->id = id; }
            void setPassword(std::string password) { this->password = password; }
            void setNombre(std::string nombre) { this->nombre = nombre; }
            void setactivo(bool activo) { this->activo = activo; }
    };
}

#endif
