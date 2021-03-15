#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>

int main(void)
{

   int stack_value = 2;
   pid_t pid;
   switch(pid = fork())
   {
     case -1:
         printf("fork failed\n");
         break;
     case 0:
         printf("fork child success\n");
         stack_value *= 10;
         break;
     default:
         printf("fork parent\n");
         if(wait(NULL)==-1)
         {
            return -1;
         }
         break;
   }

   printf("%s stack_value is %d\n", pid == 0? "child":"parent", stack_value);

   return 0;
}
