#include <stdio.h>


int f_1(int value)
{

  if(n < 1)
  {
      return 0;
  }
  
  if(n == 1 || n == 2)
  {
     return 1;
  }

  return f_1(value-1) + f_1(value-2);
  
}

int f_2(int value)
{
  if(n <1 )
     return 0;
  
  if(n==1 || n == 2)
     return 1;
  
  int res = 1;
  int pre = 1;
  int tmp = 0;
  
  for(int i = 3; i<=n; i++)
  {
     tmp = res;
     res = res + pre;
     pre = tmp;  
  }
  
  return res;
}
int main(void)
{

   printf("ceshi fei bo na 1: %x", f_1(100));
   printf("ceshi fei bo na 2: %x", f_1(100));
   return 0;
}
