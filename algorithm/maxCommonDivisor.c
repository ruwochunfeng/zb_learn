#include <stdio.h>

int gcd(int m,int n)
{
   return n==0 ? m : gcd(n,m%n);
}
int main(void)
{

   printf("ceshi max common divisor: %x", gcd(138,88));

}
