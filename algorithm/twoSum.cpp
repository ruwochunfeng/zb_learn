#include <stdio.h>

vector<int> twoSum(vector<int>& nums, int target)
{

   unordered_map<int,int> hash;
   
   vector<int> ans;
   
   for(int i = 0; i < nums.size(); i++)
   {
      int num = nums[i];
      auto pos = hash.find(target - num);
      
      if(pos == hash.end())
      {
         hash[num] = i;
      }
      else
      {
         ans.push_back(pos->second);
         ans.push_back(i);
         break;
      }
   
   }
   return ans;
}
