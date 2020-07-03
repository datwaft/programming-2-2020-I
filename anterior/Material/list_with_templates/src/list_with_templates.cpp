#include <iostream>
#include <string>

// Nota:
// `struct` es exactamente igual que class, solo que por defecto los miembros
// son `public`, en cambio en class son `private` por defecto.
// Las struct son útiles para objetos como los nodos, donde no se requiere
// funcionalidad avanzada, solamente agrupar datos.
// Para construir un struct se hace con: `Node<T>{data, next}`.
// Notese el uso de {} en lugar de ().

template<class T>
struct Node {
    T data;
    Node<T>* next;
};

template<class T>
class Iterator {
    private:
        Node<T>* current;
    public:
        Iterator(Node<T>* nodo) {
            this->current = nodo;
        }
        bool operator != (const Iterator<T>& other) {
            return this->current != other.current;
        }
        Iterator<T> operator ++ () {
            this->current = this->current->next;
            return *this;
        }
        T operator * () {
            return this->current->data;
        }
};

template<class T>
class List {
    private:
        Node<T>* first;
    public:
        List();
        List(const List&);
        ~List();
        void push(T);
        T pop();
        const T top();
        const bool isEmpty();
        Iterator<T> begin();
        Iterator<T> end();
};

template<class T>
List<T>::List() {
    this->first = nullptr;
}

template<class T>
List<T>::List(const List& list) {
    throw "me dio pereza hacer esto!";
}

template<class T>
List<T>::~List<T>() {
    while(!this->isEmpty())
    {
        this->pop();
    }
}

template<class T>
void List<T>::push(T data) {
    this->first = new Node<T>{data, this->first};
}

template<class T>
T List<T>::pop() {
    if(isEmpty())
        throw "Cannot pop from empty list";
    Node<T>* temp = this->first;
    T data = temp->data;
    this->first = this->first->next;
    delete temp;
    return data;
}

template<class T>
const T List<T>::top() {
    if(isEmpty())
        throw "Cannot top from empty list";
    return first->data;
}

template<class T>
const bool List<T>::isEmpty() {
    return first == nullptr;
}

template<class T>
Iterator<T> List<T>::begin() {
    return Iterator<T>(this->first);
}

template<class T>
Iterator<T> List<T>::end() {
    return Iterator<T>(nullptr);
}

int main() {
    List<std::string> lista;
    lista.push("10");
    lista.push("20");
    lista.push("30");
    lista.push("40");

    for (Iterator<std::string> i = lista.begin(); i != lista.end(); ++i) {
        std::cout << (*i) << std::endl;
    }

    for(auto i: lista) {
        std::cout << i << std::endl;
    }
}

