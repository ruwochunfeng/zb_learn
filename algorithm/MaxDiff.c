#include <stdio.h>

int MaxDiff(const int* number, unsigned length)
{
   if(number == nullptr || length == 0)
       return 0;
   
   int max = 0;
   int maxDiff = numbers[1] - max;
   
   for(int i = 2; i< length ; i++)
   {
       if(number[i-1]< min)
           min = number[i-1];
           
       int currDiff = number[i] - min;
       
       if(currDiff > maxDiff)
          maxDiff = currDiff;
   
   }
   
   return maxDiff;     
   
    

}
