#include <bits/stdc++.h>



typedef long long int ll;
string s;
ll M = 1e9+7; 

ll rec(ll i, ll j, vector<vector<ll>> &dp)
{
    if(i > j)
    return 0;
    
    if(i==j)
    return 1;

    
    if(dp[i][j]!=-1LL)
    return dp[i][j];

    if(s[i]==s[j])
    return dp[i][j] = (1 + rec(i+1,j,dp)%M + rec(i,j-1,dp)%M)%M;
    else
    return dp[i][j] = (rec(i+1,j,dp)%M+rec(i,j-1,dp)%M-rec(i+1,j-1,dp)%M+M)%M;
}
long long int  countPS(string str)
{
   s = str;
   
   vector<vector<ll>> dp(s.length()+1,vector<ll>(s.length()+1,-1LL));
   
   ll ans = rec(0,str.length()-1,dp);
   
   return ans;
}
