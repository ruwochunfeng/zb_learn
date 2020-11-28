#include <stdio.h>

int getMaxValue(const int* value, int rows, int cols)
{
    if(value == nullptr || rows <=0 || cols <=  0)
       return 0;
       
    int* maxValue = new int[cols];
    
    for(int i= 0; i< rows; i++)
    {
        for(int j = 0; j< cols;j++)
        {
           int left = 0;
           int up = 0;
           
           if(i>0)
              up = maxValue[j];
              
           if(j>0)
              left = maxValue[j-1];
           maxValue[j] = std::max(left, up) + value[i][j];
        }
    }
    
    int maxValue = maxValue[cols -1];
    
    delete maxValue ;
    return maxValue;

}
