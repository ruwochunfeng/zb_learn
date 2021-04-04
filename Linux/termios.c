#include <stdio.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>


 
int main(void)
{
   struct termios tp;
   char buf[100];
   tcgetattr(STDIN_FILENO, &tp);

   tp.c_lflag &= ~(ECHO | ICANON);
   tp.c_cc[VMIN]= 20;
   tp.c_cc[VTIME] = 100000;
   tcsetattr(STDIN_FILENO, TCSAFLUSH, &tp);
   printf("Pls input some info:\n");
/*   fflush(stdout);
 
   if(fgets(buf, 100, stdin) != NULL)
   {
       printf("Read : %s\n", buf);
   }*/


   tcsetattr(STDIN_FILENO, TCSANOW, &tp);

   int dev = open(STDIN_FILENO, O_RDWR);
   char buffer[tp.c_cc[VMIN]];
   read(dev, buffer, 1);
   {
      printf("Read : %s\n", buffer);
   }
   printf("Read over\n");
   return 0;
}
