#include <stdio.h>

int FindFirstIndexIs1(int num)
{
    int  index =  0;
    while(num&1==0   && index<(8*sizeof(int)))
    {
      num = num>>1;
      index++;
    }
    
    return  index;
}

bool isBit1(int num,int index)
{
   return  (num>>index) &1==1; 
}

void  FindNumsAppearOnce(int[] num, int len,int *num1,int *num2)
{
   int OrRet  =0;
   for(int i=0;i<len;i++)
   {
     OrRet ^=num[i]
   }
   
   int   index=  FindFirstIndexIs1(OrRet);
   
   for(int i=0;i<len;i++)
   {
     if(isBit1(num[i],index))
     {
       *num1 ^=num[i];
     }
     else
     {
       *num2 ^=num[i];
     }
     
   }
}
