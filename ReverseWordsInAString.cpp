#include<bits/stdc++.h>
string reverseString(string str)
{
        string ans;
        string words;
        str+= " ";
    
        vector<string> v;
        for(auto &x:str)
        {
            if(x!=' ')
                words.push_back(x);
            else
            {
                if(words=="")
                    continue;
                 v.push_back(words);
                 words = "";
            }
        }
    
        for(int i = v.size()-1; i >= 0; i--)
        {
            ans+=v[i]+" ";
        }
        
        ans.pop_back();
    
        return ans;
}
