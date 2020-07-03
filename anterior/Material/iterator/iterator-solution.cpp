#include <iostream>

using T = int;

class Array {
  private:
    int n;
    T* v;
  public:
    Array(int n) {
      this->n = n;
      v = new T[n];
    }
    virtual ~Array() {
      delete v;
    }
    T& operator [] (int k) {
      return this->v[k];
    }
    const T& operator [] (int k) const {
      return this->v[k];
    }
    int getSize() {
      return this->n;
    }
};

class Iterator {
  private:
    mutable int k;
    Array* v;
  public:
    Iterator(Array* v) {
      this->k = 0;
      this->v = v;
    }
    ~Iterator() = default;
    bool hayMas() {
      return this->k < v->getSize();
    }
    T& getSiguiente() {
      return (*v)[this->k++];
    }
    const T& getSiguiente() const {
      return (*v)[this->k++];
    }
};

int main() {
  Array* array = new Array(10);
  Iterator j = Iterator(array);
  while(j.hayMas()) {
    j.getSiguiente() = 3;
  }
  Iterator i = Iterator(array);
  while(i.hayMas()) {
    std::cout << i.getSiguiente() << " ";
  }
  std::cout << std::endl;
  delete array;
}
