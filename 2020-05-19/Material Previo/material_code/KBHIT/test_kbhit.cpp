#include <iostream>
#include "getch.h"

int main() {
  bool flag = true;
  int character = 0;
  while(flag) {
    if (kbhit()) {
      character = getch();
      std::cout << "Got character: '" << character << "'" << std::endl;
      if (character == 27)
        flag = false;
    }
    std::cout << "..." << std::endl;
  }
}
