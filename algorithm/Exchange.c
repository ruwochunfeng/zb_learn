#include <stdio.h>

void exchange(int num1, int num2)
{

    num1 = num1+num2;
    num2 = num1-num2;
    num1 = num1-num2;
}

void exchange1(int num1, int num2)
{
    num1 = num1^num2;
    num2 = num1^num2;
    num1 = num1^num2;
}  

