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

#include <iostream>

int main() {
  #ifdef WINDOWS
    std::cout << "Is windows" << std::endl;
  #else
    std::cout << "Is not windows" << std::endl;
  #endif
}

