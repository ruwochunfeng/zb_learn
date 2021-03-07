#include <stdio.h>
#include <sys/wait.h>


int main(void)
{
   FILE *fp;
   int status;
   fp = popen("ls -l", "r");
   char buf[1024];
   if(fp == NULL)
   {
      printf("fp == NULL");
   }
   
   if(wait(&status) < 0)
   {
      printf("wait(&status) < 0");
   }
   
   if(WIFEXITED(status) == 0)
   {
      printf("WIFEXITED(status) == 0");
   }
   
   while(fgets(buf, 1024, fp) !=NULL)
   {
      printf("gets(buf) is %s", buf);
   }
   
   
   pclose(fp);
}
