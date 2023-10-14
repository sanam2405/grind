#include <bits/stdc++.h> 
int N;
vector<vector<int>> D;
int dp[22][1<<17];

int rec(int level, int mask)
{
	if(mask==0)
	return D[level][0];

	if(dp[level][mask]!=-1)
	return dp[level][mask];

	int ans = 1e9;

	for(int i = 0; i < N; i++)
	{
		if(mask&(1<<i))
		{
			ans = min(ans,D[level][i]+rec(i,(mask^(1<<i))));
		}
	}

	return dp[level][mask] = ans;
}
int shortestRoute(vector<vector<int>> &distance)
{
	N = distance.size();
	D = distance;

	memset(dp,-1,sizeof(dp));

	// Initially all cities can be visited
	// N cities => 111111...11 (N 1s) => 2^N-1 => (1<<N)-1

	// Initial mask is 11111...1110 since the first city cannot be visited 
	// as we are staring from the first city itself

	int ans = rec(0,(1<<N)-2);

	return ans;
}
