#include<bits/stdc++.h>

// Trying to make b equal to a
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
        Delete = 1+rec(i,j+1);        // char in b is deleted so j+1 and i remains same
        Replace = 1+rec(i+1,j+1);    // i and j made same by replacement so i+1,j+1
        Insert = 1+rec(i+1,j);      // char in b is inserted so i+1 and j remains same
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
