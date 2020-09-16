#include <stdio.h>


unsigned short int convertToHEX(short int value)
{
   unsigned short int temp = value;
   
   if(value < 0)
   {
      temp = -value;
      temp = (~temp) + 1;
   }
   
   return temp;
}
int main(void)
{

   printf("ceshi negative value to hex: %x", convertToHEX(-5));

}
