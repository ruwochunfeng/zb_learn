#include <stdio.h>

bool    isPowerOfThree()
{    
   return   fmod(log10(n)/log10(3),1)  ==0;
}

bool    isPowerOfThree(int n)
{
   return n>0 && 1162261467%n == 0;
}
