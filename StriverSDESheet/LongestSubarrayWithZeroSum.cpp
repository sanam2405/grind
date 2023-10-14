#include <bits/stdc++.h> 
int LongestSubsetWithZeroSum(vector < int > arr) {
        
        map<int,vector<int>> m;
        
        m[0].push_back(-1);
        int sum = 0;
        
        for(int i = 0; i < arr.size(); i++)
        {
            sum+=arr[i];
            m[sum].push_back(i);
        }
        
        sum = 0;
        int ans = -1;
        for(int i = 0; i < arr.size(); i++)
        {
            
            sum+=arr[i];
            int dist = -1;
            for(auto &x:m[sum])
            {
                dist = max(dist,abs(x-i));
            }
            
            ans = max(dist,ans);
        }
    
        return ans;
}
