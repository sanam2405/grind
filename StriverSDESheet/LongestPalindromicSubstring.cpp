#include<bits/stdc++.h>


string s;
int n;
bool dp[1010][1010];
bool done[1010][1010];

bool rec(int i, int j)
{
    if(i>=j)
        return true;
    if(done[i][j])
        return dp[i][j];
    
    done[i][j] = 1;
    
    if(s[i]==s[j])
        return dp[i][j] = rec(i+1,j-1);
    else
        return dp[i][j] = false;
}

string longestPalinSubstring(string str)
{
        s = str;
        n = s.length();
        memset(dp,false,sizeof(dp));
        memset(done,false,sizeof(done));
        string ans;
    
        int maxi = -1;
        int l,r;
        for(int i = 0; i < n; i++)
        {
            for(int j = i; j < n; j++)
            {
                if(rec(i,j))
                {
                    if(max(i, j) - min(i, j) + 1>maxi)
                    {
                        maxi = max(i, j) - min(i, j) + 1;
                        l = min(i, j);
                        r = max(i, j);
                    }
                }
            }   
         }
    
        ans = s.substr(l,r-l+1);
    
        return ans;
    
        
        
}
