#include <stdio.h>

void  FindNumSumisN(int[] num, int len, int N)
{
    int first  = 0;
    int end = len;
    
    while(first <  end)
    {
        int sum = num[first]+num[end];
        if(sum <N)
        {
           first++;
        }
        else if(sum>N)
        {
           end--;
        }
        else
        {
          //find result
          return;
        }
    }
    
    //no find  result
}
