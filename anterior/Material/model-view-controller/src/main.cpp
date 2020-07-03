#include "../include/Presentacion/LogIn/vista.h"

int main() {
    Presentacion::Login::Vista* vista = new Presentacion::Login::Vista();
    vista->ejecutar();
    delete vista;
}
