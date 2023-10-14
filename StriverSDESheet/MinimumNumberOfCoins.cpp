#include<bits/stdc++.h>
int dp[11][101010];
bool done[11][101010];

int rec(int level, int amount, vector<int> &notes)
{
    if(amount < 0 || level >= notes.size())
        return 1e9;
    if(amount==0)
        return 0;
    
    if(done[level][amount])
        return dp[level][amount];
    
    done[level][amount]=1;
    
    int take = 1+rec(level,amount-notes[level],notes);
    int notTake = rec(level+1,amount,notes);
    
    return dp[level][amount] = min(take,notTake);
}
int findMinimumCoins(int amount) 
{
    vector<int> notes = {1,2,5,10,20,50,100,500,1000};
    
    memset(dp,sizeof(dp),0);
    memset(done,sizeof(done),false);
    
    int ans = rec(0,amount,notes);
    
    return ans;
}
