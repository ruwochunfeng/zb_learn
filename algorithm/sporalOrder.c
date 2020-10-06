#include <stdio.h>


/*
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16

the result is 1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10
*/
void  spiralOrderPrint(int[][] n)
{
   int first_Row = 0;
   int first_col = 0;
   int end_Row = n.length-1;
   int end_Col = n[0].length-1;
   
   while(first_Row  <=end_Row && first_col<=end_Col)
   {
        printResult(n,first_Row++,first_col++, end_Row--, end_Col--);
   }
}

void printResult(int[][] n,  int fr, int fc,  int er,int ec)
{
   if(fr == er)
   {
      for(int i = 0; i < ec; i++)
         printf("the result is %d\n", n[er][i]);
   }
   else if(fc == ec)
   {
       for(int i = 0; i < fr; i++)
         printf("the result  is %d\n", n[i][fc]);
   }
   else
   {
       int curC  = fc;
       int curR  = fr;
       while(curC  != ec)
       {
           printf("the result  is %d\n", n[fr][curC]);
           curC++;
       }
       while(curR  != er)
       {
           printf("the result  is %d\n", n[curR][ec]);
           curR++;
       }
       while(curC  != fc)
       {
           printf("the result  is %d\n", n[er][curC]);
           curC--;
       }
       while(curR  != fr)
       {
           printf("the result  is %d\n", n[curR][fc]);
           curR--;
       }
   }

}
