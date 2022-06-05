#include<bits/stdc++.h>
vector<int> subset;
vector<vector<int>> ans;
void rec(int level, vector<int> &v)
{
    if(level==v.size())
    {
        sort(subset.begin(),subset.end());
        ans.push_back(subset);
        return;
    }
    
    subset.push_back(v[level]);
    rec(level+1,v);
    subset.pop_back();
    rec(level+1,v);
}
vector<vector<int>> pwset(vector<int>v)
{
        rec(0,v);
    
        return ans;
}
