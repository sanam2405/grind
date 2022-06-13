#include<bits/stdc++.h>

bool done[11];
vector<string> ans;
string path;
string str;
void rec()
{
    
    if(path.length()==str.length())
    {
        ans.push_back(path);
        return;
    }
    
    for(int i = 0; i < str.length(); i++)
    {
        if(!done[i])
        {
            path.push_back(str[i]);
            done[i]=1;
            rec();
            path.pop_back();
            done[i]=0;
        }
    }
}


vector<string> findPermutations(string &s) {
            str = s;
            rec();
            return ans;
}
