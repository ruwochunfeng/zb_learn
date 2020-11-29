#include <stdio.h>

int minPathSum2(int[][] m)
{
   if(m ==nullptr || m.length  == 0|| m[0] ==nullptr || m[0].length ==0)
       return 0;
       
   int row = m.length;
   int col = m[0].length;
   
   int[][] dp = new int[row][col];
   
   dp[0][0] = m[0][0];
   
   for(int i = 1; i <row; i++)
   {
      dp[i][0] = dp[i-1][0] + m[i][0];
   
   }
   
   for(int i = 1; i < col; i++)
   {
      dp[0][j] = dp[0][j-1] + m[0][j];
   }
   
   for(int i =1; i < row; i++)
   {
      for(int j =1; j< ccol; j++)
      {
         dp[i][j] = std::min(dp[i-1][j], dp[i][j-1]) + m[i][j];
      }
   
   
   }
   return dp[row-1][col -1];
} 
