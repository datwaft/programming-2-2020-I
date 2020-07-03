#include "modelo.h"
#include "controlador.h"

#include <iostream>
#include <string>

namespace Presentacion {
    namespace Login {
        class Vista {
            private:
                Modelo* modelo;
                Controlador* controlador;
            public:
                Vista() {
                    modelo = new Modelo();
                    controlador = new Controlador(modelo);
                }
                ~Vista() {
                    delete modelo;
                    delete controlador;
                }
                void ejecutar() {
                    std::string id;
                    std::string password;
                    std::cout << "Bienvenido." << std::endl;
                   
                    bool hasloggedin = false;
                    while(!hasloggedin)
                    {
                        id = "";
                        password = "";
                        modelo->setUsuario(nullptr);
                        while(id.empty()) {
                            std::cout << "Por favor digite su nombre de usuario: ";
                            std::getline(std::cin, id);
                        }
                        while(password.empty()) {
                            std::cout << "Por favor digite su nombre de password: ";
                            std::getline(std::cin, password);
                        }

                        modelo->setUsuario(new Logica::Persona(id, password, "", ""));
                        hasloggedin = controlador->LogIn();
                        if (!hasloggedin)
                            std::cout << "Datos invalidos." << std::endl; 
                    }
                    /* Presentacion::MenuPrincipal::Vista* menuprincipal = new Presentacion::MenuPrincipal::Vista(); */
                    /* menuprincipal->ejecutar(); */
                }
        };
    }
}
