//code from http://cboard.cprogramming.com/sitemap/t-27714.html . Slight patches by theJ

#if !defined(__termios_H)
#include <termios.h>
#endif
#if !defined(__unistd_H)
#include <unistd.h>
#endif
#if !defined(__STDIO_H)
#include <stdio.h>
#endif

int getch(void)
{
  struct termios oldt,
    newt;
  int ch;
  tcgetattr( STDIN_FILENO, &oldt );
  newt = oldt;
  newt.c_lflag &= ~( ICANON | ECHO );
  tcsetattr( STDIN_FILENO, TCSANOW, &newt );
  ch = getchar();
  tcsetattr( STDIN_FILENO, TCSANOW, &oldt );
  return ch;
}
