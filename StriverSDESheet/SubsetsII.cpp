#include<bits/stdc++.h>

vector<int> subset;
vector<vector<int>> ans;

void rec(int level,vector<int> &arr)
{
    if(level==arr.size())
    {
        sort(subset.begin(),subset.end());
        ans.push_back(subset);
        return;
    }
    
    subset.push_back(arr[level]);
    rec(level+1,arr);
    subset.pop_back();
    
    while(level+1 < arr.size() && arr[level]==arr[level+1])
    {
        level++;
    }
    
    rec(level+1,arr);
}

vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
        sort(arr.begin(),arr.end());
        subset.clear();
        ans.clear();    
    
        rec(0,arr);
        sort(ans.begin(),ans.end());
        return ans;
}
