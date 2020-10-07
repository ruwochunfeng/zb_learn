#include <stdio.h>

int flip(int value)
{
   return n^1;
}

int sign(int n)
{
   return  flip((n>>31) & 1);
}

int getMax1(int a, int b)
{
   int c = a -b;
   int scA = sign(c);
   int scB = flip(scA);
   return  a * scA + b * scB;

}

int getMax2(int a, int b)
{
   int c = a -b;
   int sa  =  sign(a);
   int sb = sign(b);
   int sc = sign(c);
   int diffSab = sa ^ sb;
   int sameSab = flip(diffSab);
   int returnA = diffSab * sa + sameSab * sc;
   int returnB = flip(returnA);
   return a * returnA + b * returnB;
}

