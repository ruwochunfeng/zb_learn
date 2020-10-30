#include <stdio.h>


void multiply(const vector<double>& array1, vector<double>& array2)
{

   int len1 = array1.size();
   int len2 = array2.size();
   
   if(len1 == len2 && len2 >1)
   {
      array2[0] = 1;
      for(int i = 0; i<len1;i++)
      {
         array2[i] =array2[i-1]* array1[i-1];
         
      }
      
      double temp =1;
      
      for(int i = len1-2;i>=0;--i)
      {
         temp *= array1[i+1];
         array2[i] *= temp;
       }
   }
}

