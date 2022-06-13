#include<bits/stdc++.h>

string a,b;
int dp[1111][1111];
bool done[1111][1111];

int rec(int i, int j)
{
    
    if(i==a.length()&&j==b.length())
        return 0;
    if(i > a.length() || j > b.length())
        return 1e9;
    
    if(done[i][j])
        return dp[i][j];
    
    done[i][j] = 1;
    
    int Delete;
    int Replace;
    int Insert;
    
    if(a[i]==b[j])
    {
        return dp[i][j] =  rec(i+1,j+1);
    }
    else
    {
        Delete = 1+rec(i,j+1);
        Replace = 1+rec(i+1,j+1);
        Insert = 1+min(rec(i,j+1),rec(i+1,j));
        return dp[i][j] = min({Delete,Replace,Insert});
    }
    
    
}

int editDistance(string str1, string str2)
{
        a = str1;
        b = str2;
        memset(dp,0,sizeof(dp));
        memset(done,false,sizeof(done));
        int ans = rec(0,0);
        return ans;
}
