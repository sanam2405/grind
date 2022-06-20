#include<bits/stdc++.h>

int n;
string str;

int dp[111];
bool done[111];

bool checkPalin(int low, int high)
{
     while (low < high)
     {
          if (str[low++] != str[high--])
               return false;
     }

     return true;
}

int rec(int level)
{
     if (level == n)
          return 0;

     if (done[level])
          return dp[level];

     done[level] = 1;
     int ans = INT_MAX;
     for (int i = level; i < n; i++)
     {
          if (checkPalin(level, i))
          {
               int cost = 1 + rec(i + 1);
               ans = min(ans, cost);
          }
     }

     return dp[level] = ans;
}

int palindromePartitioning(string s) {
    
    str = s;
    n = str.length();
    memset(dp,0,sizeof(dp));
    memset(done,false,sizeof(done));
    int ans = rec(0) - 1;
    return ans;
}
