#include <stdio.h>

int lengthOfLIS(int[] nums)
{
   int dp = new int[nums.length];
   
   for(int i = 0; i< nums.length; i++)
   {
      for(int j = 0; j <i; j++)
      {
         if(nums[i] >  nums[j])
         {
            dp[i]  =  Math.max(dp[i], dp[j]+1);
         }
      
      }
   }
   
   int  res =  0;
   
   for(int i = 0; i  <  dp.length; i++)
   {
        res = Math.max(res, dp[i]);
   }
   
   return res;
}