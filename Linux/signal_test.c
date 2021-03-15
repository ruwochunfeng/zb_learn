#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>


static void Handler(int sig)
{
   static int count = 0;

   if(sig == SIGINT)
   {
      count++;

      printf("Caught SIGINT : %d\n", count);
      return;
   }

   printf("Caught other Signal\n");
   exit(0);
}


int main(void)
{
   if(signal(SIGINT, Handler) == SIG_ERR)
   {
       return -1;
   }

   if(signal(SIGQUIT, Handler) == SIG_ERR)
   {
       return -1;
   }

   for(;;)
      pause();
}
