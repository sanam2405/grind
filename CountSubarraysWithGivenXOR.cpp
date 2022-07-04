#include <bits/stdc++.h> 
int subarraysXor(vector<int> &arr, int k)
{
    map<int,int> m;
    int ans = 0;
    int xorr = 0;
    
    for(auto &x:arr)
    {
        xorr^=x;
           
        if(xorr==k)
            ans++;
        
        if(m.find(xorr^k)!=m.end())
            ans+= m[xorr^k];
        
        m[xorr]++;
    }
    
    return ans;
}
