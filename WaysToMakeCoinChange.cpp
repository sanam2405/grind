long long a[11];
long long N;
long long dp[11][2222];;
bool done[11][2222];

long long rec(int level, long long sum)
{
    if(sum==0)
        return 1;
    if(level==N || sum < 0)
        return 0;
    if(done[level][sum])
        return dp[level][sum];
    done[level][sum] = 1;
    long long take = rec(level,sum-a[level]);
    long long notTake = rec(level+1,sum);
    return dp[level][sum] = take+notTake;
}
long countWaysToMakeChange(int *denominations, int n, int value)
{
    	N = (long long)n;
    for(int i = 0; i < n; i++)
        a[i] = (long long)denominations[i];
    for(int i = 0; i < 11; i++)
    {
        for(int j = 0; j < 2222; j++)
        {
            dp[i][j]=0;
            done[i][j]=false;
        }
    }
    long long ans = rec(0,value);
    return ans;
}
