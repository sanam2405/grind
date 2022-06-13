#include <bits/stdc++.h>
string str;
vector<vector<string>> ans;
vector<string> path;

bool check(int i, int j, string& str)
{
    while(i < j)
    {
        if(str[i++]!=str[j--])
            return false;
    }
    
    return true;
}
void rec(int level)
{
    
    if(level==str.length())
    {
        ans.push_back(path);
        return;
    }
    
    for(int i = level; i < str.length(); i++)
    {
        if(check(level,i,str))
        {
            path.push_back(str.substr(level,i-level+1));
            rec(i+1);
            path.pop_back();
        }
    }
}
vector<vector<string>> partition(string &s) 
{
        str = s;
        rec(0);
    
    
        return ans;
}
