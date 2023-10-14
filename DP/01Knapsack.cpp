#include <bits/stdc++.h>



int rec(int level, int currWeight, vector<int> &weight, vector<int> &value, vector<vector<int>> &dp)
{
	if(level==weight.size())
	return 0;

	if(dp[level][currWeight]!=-1)
	return dp[level][currWeight];

	int take = 0, notTake = 0;

	if(currWeight-weight[level] >= 0)
	take = value[level] + rec(level+1,currWeight-weight[level],weight,value,dp);

	notTake = 0 + rec(level+1,currWeight,weight,value,dp);

	return dp[level][currWeight] = max(take,notTake);

}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{


	vector<vector<int>> dp(n+1,vector<int>(maxWeight+1,-1));
	int ans = rec(0,maxWeight,weight,value,dp);

	return ans;
}
