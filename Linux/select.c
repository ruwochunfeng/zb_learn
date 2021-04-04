#include <stdio.h>
#include <sys/wait.h>
#include <sys/select.h>
#include <sys/time.h>


 
int main(void)
{
   fd_set readfds, writefds;

   int ready;

   int numfd = 2;
   struct timeval timeout;

   timeout.tv_sec = 5;
   timeout.tv_usec = 0;



   FD_ZERO(&readfds);
   FD_ZERO(&writefds);
   int maxfd = numfd +1;
   ready = select(numfd, &readfds, &writefds, NULL, &timeout);

   if(ready == -1)
   {
       printf("select error");

       return -1;
   }
       
   printf("select ceshi");
   return 0;
}
