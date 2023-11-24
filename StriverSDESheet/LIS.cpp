#include<bits/stdc++.h>
// int longestIncreasingSubsequence(int arr[], int n)
// {
//         vector<int> dp(n,1);
    
//         for(int i = 0; i < n; i++)
//         {
//             for(int j = 0; j < i; j++)
//             {
//                 if(arr[j] < arr[i])
//                 dp[i] = max(dp[i],1+dp[j]);
//             }
//         }
    
//         int ans = 1;
    
//         for(auto &x:dp)
//             ans =max(x,ans);
    
//         return ans;
// }

int rec(int level, int arr[], int n, vector<int> &dp)
{
    if(level==n)
    return 0;

    if(dp[level]!=-1)
    return dp[level];

    int ans = 1;
    int currentElement = arr[level];
    for(int i = level-1; i >= 0; i--)
    {
        if(currentElement > arr[i])
        {
            ans = max(ans,1+rec(i,arr,n,dp));
        }
    }

    return dp[level] = ans;
}

int longestIncreasingSubsequence(int arr[], int n)
{
    vector<int> dp(n+1,-1);
    int ans = 1;
    for(int i = 0; i < n; i++)
    ans = max(ans,rec(i,arr,n,dp));

    return ans;
}

