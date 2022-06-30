#include<bits/stdc++.h>
vector<int> slidingWindowMaximum(vector<int> &nums, int &k)
{
       int n = nums.size();
    
       multiset<int> ms;
       vector<int> ans;
    
      
        for(int i = 0; i < k; i++)
        {
            ms.insert(nums[i]);
        }
    
        auto it = ms.end();
        it--;
        ans.push_back(*it);
        
        int idx = 0;
        for(int i = k; i < n; i++)
        {
            int previous = nums[idx++];
            ms.erase(ms.find(previous));
            
            ms.insert(nums[i]);
            
            auto it = ms.end();
            it--;
            ans.push_back(*it);

        }
    
        return ans;
}
