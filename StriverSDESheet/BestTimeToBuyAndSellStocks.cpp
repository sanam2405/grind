#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    
        int mini = INT_MAX;
        int ans = 0;
        int n = prices.size();
      
    
        for(int i = 0; i < n; i++)
        {
            mini = min(mini,prices[i]);
            ans = max(ans,prices[i]-mini);
        }
    
        return ans;
}
