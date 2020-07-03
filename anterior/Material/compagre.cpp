#include <iostream>

class A {
    public:
        std::string name;
};

class B {
    public:
        std::string name;
};

class C {
    public:
        std::string name;
};

class X {
    private:
        A* a; // Composicion.
        B* b; // Composicion.
        C* c; // Agregacion.
    public:
        X(C* c) {
            this->a = new A();
            this->b = new B();
            this->c = c;
        }
        ~X() {
            delete a;
            delete b;
        }
};

int main() {
    C* c = new C();
    c->name = "Hola mundo";
    X* x = new X(c);
    delete x;
    std::cout << c->name << std::endl;
    delete c;
}

