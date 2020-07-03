// Nota:
// `struct` es exactamente igual que class, solo que por defecto los miembros
// son `public`, en cambio en class son `private` por defecto.
// Las struct son útiles para objetos como los nodos, donde no se requiere
// funcionalidad avanzada, solamente agrupar datos.

template <class T>
struct Node {
    T data;
    Node<T>* next;
}

template 
