#include <stdio.h>

bool checkValid(int*numbers, int len, int num)
{
   int count = 0;
   
   for(int i=0;i<len;i++)
   {
       if(numbers[i]==num)
           count++;
   }
   
   if(count *2 <  len)
      return  false;
      
   return true;

}
int MoreThanHalfNum(int* numbers, int len)
{
    int result = numbers[0];
    int times = 1;
    
    for(int i = 1;i<len;i++)
    {
       if(times ==0)
       {
         result =  numbers[i];
       }
       else if(result==numbers[i])
       {
         times++;
       }
       else
       {
         times--;
       }
    }  
    
    if(!checkValid(number,len,result))
        result =  0;
    return  result;
}    

