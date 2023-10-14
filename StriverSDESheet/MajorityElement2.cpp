#include <bits/stdc++.h> 
vector<int> majorityElementII(vector<int> &arr)
{
    
            int target = arr.size()/3;

           map<int,int> m;
            for(auto &x:arr)
                m[x]++;
    
            vector<int> ans;
            
            for(auto &x:m)
            {
                if(x.second > target)
                    ans.push_back(x.first);
            }
    
            return ans;
}
