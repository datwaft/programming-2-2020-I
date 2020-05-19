#include <iostream>
#include "getch.h"

int main() {
  int character = 0;
  while (character != 27) {
    std::cout << "Digite una tecla: ";
    character = getch();
    std::cout << "\nLa tecla presionada fue: " << character << std::endl;
  }
}
