#include <stdio.h>

unsigned int reverseBits(unsigned int n)
{
   unsigned ing ans = 0;
   
   for(int i = 0;i < 32;++i)
   {
       ans <<=1;
       ans += n&1;
       n >>=1;
   
   }
   
   return ans;

}
