#include<bits/stdc++.h>
vector<int> countDistinctElements(vector<int> &arr, int k) 
{
    int n = arr.size();
    vector<int> ans;
    map<int,int> m;
    
    for(int i = 0; i < k; i++)
            m[arr[i]]++;
    
    ans.push_back(m.size());
    
    int idx = 0;
    
    for(int i = k; i < n; i++)
    {
        int previous = arr[idx++];
        m[previous]--;
        m[arr[i]]++;
        if(m[previous]==0)
            m.erase(previous);
        
      
        ans.push_back(m.size());
    }
    
    return ans;
	
}
