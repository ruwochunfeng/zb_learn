#include <stdio.h>


void Permutation(char* str)
{
   if(str==nullptr)
      return;
   Permutation(str,str)

}
void Permutation(char* str,char* begin)
{

   if(*begin=='\0')
   {
      printf("%s\n",str);
   }
   else
   {
      for(char* pCh = begin;pCh!='\0';++pCh)
      {
         char tmp=*pCh;
         *pCh = *begin;
         *begin = tm;
         
         Permutation(str,begin+1);

         tmp=*pCh;
         *pCh = *begin;
         *begin = tm;       
         
      
      }
   
   }

}

