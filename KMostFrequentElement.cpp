#include<bits/stdc++.h>
vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
        map<int,int> m;
    
        for(auto &x:arr)
            m[x]++;
    
        vector<pair<int,int>> freq;
    
        for(auto &x:m)
            freq.push_back({x.second,x.first});
    
        sort(freq.begin(),freq.end());
        reverse(freq.begin(),freq.end());
    
        vector<int> ans;
    
        for(int i = 0; i  < k; i++)
            ans.push_back(freq[i].second);
        
        sort(ans.begin(),ans.end());
    
        return ans;
}
