#include<bits/stdc++.h>
string a,b;
int dp[1001][1001];
bool done[1001][1001];
int rec(int i, int j)
{
    if(i>=a.length()||j>=b.length())
        return 0;
    if(done[i][j])
        return dp[i][j];
    done[i][j]=1;
    if(a[i]==b[j])
    {
        return dp[i][j] = 1+rec(i+1,j+1);
    }
    else
    {
        return dp[i][j] =  max(rec(i+1,j),rec(i,j+1));
    }
}
int lcs(string s, string t)
{
	a = s;
    	b = t;
    	memset(dp,0,sizeof(dp));
    	memset(done,false,sizeof(done));
    	int ans = rec(0,0);
    	return ans;
}
