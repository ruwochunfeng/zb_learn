#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>


static void Handler(int sig)
{
   static int count = 0;

   if(sig == SIGINT)
   {
      //second siganl is arrived, it will delay the handler is over
      count++;
      sleep(5);
      printf("Caught SIGINT : %d\n", count);
      return;
   }

   printf("Caught other Signal\n");
   exit(0);
}


int main(void)
{
   struct sigaction act;
   act.sa_handler = Handler;
   if(sigaction(SIGINT, &act,NULL) == -1)
   {
       return -1;
   }

   if(sigaction(SIGQUIT, &act,NULL) == -1)
   {
       return -1;
   }

   for(;;)
   {
      printf("ceshi pause\n");
      pause();
   }
}
