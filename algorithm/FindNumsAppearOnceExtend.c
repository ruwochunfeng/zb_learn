#include <stdio.h>

void  FindNumsAppearOnce(int[] num, int len,int *num1)
{
   int OrRet  =0;
   
   int result[32] = {0};
   
   for(int i = 0;i<len;i++)
   {
      for(int j = 31;j>=0;i--)
      {
         if((num>>j)&1 == 1)
            result[j]++;
      }
   }
   
   for(int i = 0;i<32;i++)
   {
      *num1 = (*num1)<<1;
      *num1 += result[j]%3;   
   }
}
