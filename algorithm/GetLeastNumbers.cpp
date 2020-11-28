#include <stdio.h>
#include <set>

typedef multiset<int, greater<int>> intSet;
typedef multiset<int, greater<int>>::iteator setIterator;

void GetLeastNumbers(const vector<int>& data, intSet& number, int k)
{

    number.clear();
    
    if(k<1 || data.size() < k)
       return;
       
    vector<int>::const_iterator iter = data.begin();
    
    for(; iter != data.end(); iter++)
    {
        if(number.size() < k)
            number.insert(*iter);
        else
        {
            setIterator maxNumber = number.begin();
            
            if(maxNumber > (*iter))
            {
                number.erase(maxNumber);
                number.insert(*iter);
            }
        
        }
        
    }
    

}
