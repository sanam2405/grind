#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;

// rec(level,lastLevel) return {LIS,noOfLIS} 
// starting from level till the end

// Adjust the lastLevel indices since it can be -1

vector<ll> all;
pair<ll,ll> rec(ll level, ll lastLevel, vector<vector<pair<ll,ll>>> &dp)
{
   if(level==all.size())
   return {0,1};

   if(dp[level][lastLevel+1].first!=-1)
   return dp[level][lastLevel+1];

   ll length = 0, count = 0;
   if(lastLevel==-1 || all[level] > all[lastLevel])
   {
       pair<ll,ll> take = rec(level+1,level,dp);
       ll newLength = take.first+1;
       if(newLength > length)
       {
           length = newLength;
           count = take.second;
       }
       else if(newLength == length)
       {
           count += take.second;
       }
   }

   pair<ll,ll> notTake = rec(level+1,lastLevel,dp);
   ll newLength = notTake.first;
   if(newLength > length)
   {
       length = newLength;
       count = notTake.second;
   }
   else if(newLength == length)
   {
       count += notTake.second;
   }

   return dp[level][lastLevel+1] = {length,count};
}

ll findNumberOfLIS(vector<ll>& nums) {
   all = nums;

   vector<vector<pair<ll,ll>>> dp(all.size(),vector<pair<ll,ll>>(all.size()+1,make_pair(-1,-1)));
   pair<ll,ll> ans = rec(0,-1,dp);

   return ans.second;
}


void solve()
{
    ll n;
    cin >> n;
    vector<ll> nums(n);

    for(auto &x:nums)
     cin >> x;

     ll countOfLIS = findNumberOfLIS(nums);

     cout << countOfLIS << "\n";
}



int main() {

#ifndef ONLINE_JUDGE
     freopen("input.txt", "r", stdin);
     freopen("output.txt", "w", stdout);
#endif

     ios_base::sync_with_stdio(false);
     cin.tie(nullptr);
     cout.tie(nullptr);

     ll t;
     t = 1;
     cin >> t;
     while (t--)
     {
          solve();
     }

     return 0;
}