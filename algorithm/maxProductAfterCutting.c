#include <stdio.h>

void  maxProductAfterCutting(int len)
{

   if(len < 2)
      return  0;
   if(len == 2)
      return 1;
   if(len == 3)
      return 2;
      
   int times_3 = len/3;
   
   if(len - times_3 * 3 ==1)
       times_3 --;
   
   int times_2 = (len - times_3)/2;
   
   return (int)(pow(3,times_3))*(int)(pow(2,times_2));
   

}

