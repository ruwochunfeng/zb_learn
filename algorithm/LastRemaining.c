#include <stdio.h>

int LastRemaining(unsigned int n, unsigned int m)
{

   if(n<1 ||m<1)
      return -1;
      
   int last = 0;
   
   for(int i = 2;i<=n;i++)
       last = (last+m)%i;
       
   return last;
}

int LastRemaining(unsigned int n, unsigned int m)
{
   if(n<1 ||m<1)
      return -1;
      
   unsigned int i = 0;
   
   list<int> numbers;
   for(int i = 0;i<n;i++)
       numbers.push_back(i);
       
   list<int>::iterator curr = numbers.begin();
   
   while(numbers.size()>1)
   {
      for(int i = 0; i<m;i++)
      {
         curr++;
         if(current == numbers.end())
             current = numbers.begin();
      }
      
      list<int>::iterator next = ++curr;
      if(next == numbers.end())
           next = numbers.begin();
           
      --curr;
      numbers.erase(curr);
      
      curr = next;
   }
}
