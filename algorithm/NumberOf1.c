#include <stdio.h>


void  Numberof1(int n)
{
   int count = 0;
   
   while(n)
   {
      count++;
      
      n= (n-1)&n;
   
   }
   
   return count;
}
