#include<bits/stdc++.h>

int N;
int dp[1111][1111];
bool done[1111][1111];

int rec(int level, int weight, vector<int> &values, vector<int> &weights)
{
    if(level==N)
        return 0;
    if(done[level][weight])
        return dp[level][weight];
    
    done[level][weight] = 1;
    
    int pick = -1e9;
    int notPick = -1e9;
    
    if(weight-weights[level] >= 0)
    {
        pick = values[level]+rec(level+1,weight-weights[level],values,weights);
    }
    
    notPick = rec(level+1,weight,values,weights);
    
    return dp[level][weight] = max(pick,notPick);
}

int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
    N = n;
    memset(dp,0,sizeof(dp));
    memset(done,false,sizeof(done));
    int ans = rec(0,w,values,weights);
    return ans;
}
