#include <stdio.h>


char FirstNotRepeating(char*   string)
{
   if(string ==nullptr)
       return  '0';
   unsigned  int  hashTable[256];
   
   char*  pHashKey =    string;
   
   while(*(pHashKey)!='0')
       hashTable[*(pHashKey++)]++;
   
   pHashKey =    string;
   while(*pHashKey  !='\0')
   {
      if(hastTable[*pHashKey]==1)
          return *pHashKey;
      pHashKey++;
   }
   
   
   return  '\0';
}

