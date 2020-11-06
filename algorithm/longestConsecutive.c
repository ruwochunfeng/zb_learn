#include <stdio.h>

int longestConsecutive(vector<int>& nums)
{

    unordered_set<int> hash;
    for(const int & num:nums)
    {
       hash.insert(num);
    }
    
    int ans = 0;
    
    while(!hash.empty())
    {
       int cur = *(hash.begin());
       hash.erase(cur);
       int next = cur +1,prev = cur -1;
       while(hash.count(next))
       {
          hash.erase(next++);
       }
    
       while(hash.count(prev))
       {
          hash.erase(prev--);
       }
       ans = max(ans,next-prev-1);
       
    }

    return ans;
}
