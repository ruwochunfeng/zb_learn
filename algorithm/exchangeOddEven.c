#include <stdio.h>

void RecoderOddEven(int *pData, int len)
{

   if(pData == nullptr || len == 0)
   {
      return;
   
   }
   
   int *pBegin = pData;
   int *pEnd = pData + len -1;
   
   while(pBegin < pEnd)
   {
      while(pBegin < pEnd && (*pBegin & 0x01) != 0)
         pBegin++;
      while(pBegin < pEnd && (*pEnd & 0x01) == 0)
         pEnd++;
      
      if(pBegin < pEnd)
      {
         int tmp  =  *pBegin;
         *pBegin = *pEnd;
         *pEnd = tmp; 
      }
   }

}
