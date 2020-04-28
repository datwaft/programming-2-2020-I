#include <iostream>
#include <exception>
#include <stdexcept>

using T = int;

struct Node {
  T data;
  Node* next;
};

class LinkedList {
  private:
    Node* first;
  public:
    LinkedList() {
      this->first = nullptr;
    }

    ~LinkedList() {
      Node* aux;
      while (this->first) {
        aux = this->first;
        this->first = this->first->next;
        delete aux;
      }
    }

    void push(T data) {
      if (!this->first) {
        this->first = new Node{data, nullptr};
      } else {
        Node* aux = this->first;
        while (aux->next) {
          aux = aux->next;
        }
        aux->next = new Node{data, nullptr};
      }
    }

    T pop() {
      if (!this->first) {
        throw std::runtime_error("Cannot pop an empty LinkedList");
      } else {
        T data;
        if (!this->first->next) {
          data = this->first->data;
          delete this->first;
          this->first = nullptr;
        } else {
          Node* aux = this->first;
          while (aux->next->next) {
            aux = aux->next;
          }
          Node* to_delete = aux->next;
          data = to_delete->data;
          delete to_delete;
          aux->next = nullptr;
        }
        return data;
      }
    }
};

int main() {
  try {
    std::cout << "The linked list has been created" << std::endl;
    LinkedList* list = new LinkedList();
    list->push(10);
    std::cout << list->pop() << std::endl;
    delete list;
  } catch (std::exception ex) {
    std::cerr << "Unhandled exception: \"" << ex.what() << "\"" << std::endl;
  }
}
