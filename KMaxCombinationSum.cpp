#include<bits/stdc++.h>
vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k){
        
    vector<int> all;
    vector<int> ans;
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            {
                all.push_back(a[i]+b[j]);
            }
    }    
    
    sort(all.begin(),all.end(),greater<int>());
    int idx = 0;
    while(k--)
    {
        ans.push_back(all[idx++]);
    }
    
    return ans;
}
