#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <pthread.h>


static void * func(void *arg)
{
   char* result = (char*) arg;
   sleep(3);
   printf(" result is %s\n", result);
   
   return (void *)result;
}
 
int main(void)
{
   pthread_t tid;
   char* param = "ceshi";

   void *res;
   pthread_create(&tid, NULL, func, (void*) param);
   pthread_join(tid, &res);
   printf("func result is %s\n", (char*)res);

   return 0;
}
