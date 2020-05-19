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

#ifndef GETCH_H_
#define GETCH_H_

#ifdef WINDOWS
  #include <conio.h>
#else
  #include <sys/ioctl.h>
  #include <unistd.h>
  #include <termios.h>
  #include <stropts.h>
#endif

#ifdef WINDOWS
  #define getch _getch
  #define kbhit _kbhit
#else
  char getch(void) {
    char buf = 0;
    struct termios old = {0};
    fflush(stdout);
    if(tcgetattr(0, &old) < 0)
      perror("tcsetattr()");
    old.c_lflag &= ~ICANON;
    old.c_lflag &= ~ECHO;
    old.c_cc[VMIN] = 1;
    old.c_cc[VTIME] = 0;
    if(tcsetattr(0, TCSANOW, &old) < 0)
      perror("tcsetattr ICANON");
    if(read(0, &buf, 1) < 0)
      perror("read()");
    old.c_lflag |= ICANON;
    old.c_lflag |= ECHO;
    if(tcsetattr(0, TCSADRAIN, &old) < 0)
      perror("tcsetattr ~ICANON");
    return buf;
  }
  int kbhit(void) {
    static const int STDIN = 0;
    termios term;
    tcgetattr(STDIN, &term);
    term.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN, TCSANOW, &term);
    setbuf(stdin, NULL);
    int bytesWaiting;
    ioctl(STDIN, FIONREAD, &bytesWaiting);
    return bytesWaiting;
  }
#endif

#endif /* GETCH_H_ */
