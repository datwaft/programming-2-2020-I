#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
  #ifndef WINDOWS
    #define WINDOWS
  #endif
#elif __APPLE__
  #ifndef MACOS
    #define MACOS
  #endif
#else
  #ifndef LINUX
    #define LINUX
  #endif
#endif

#ifdef WINDOWS
  #include <windows.h>
#endif
#include <iostream>

int main() {
  #ifdef WINDOWS
  HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
  DWORD dwMode = 0;
  GetConsoleMode(hOut, &dwMode);
  dwMode |= 4;
  SetConsoleMode(hOut, dwMode);
  #endif

  std::cout << "\x1b[1;31m" << "Esto es de color rojo brillante" << "\x1b[0m" << std::endl;
  std::cout << "\x1b[31m" << "Esto es de color rojo opaco" << "\x1b[0m" << std::endl;
  std::cout << "\x1b[1;34m" << "Esto es de color azul brillante" << "\x1b[0m" << std::endl;
  std::cout << "\x1b[34m" << "Esto es de color azul opaco" << "\x1b[0m" << std::endl;
}
