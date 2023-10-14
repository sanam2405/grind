/*

Total number of ways
to create sum == k
where each item may be
taken multiple times

*/

#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef long double ld;

ll n, k;
ll arr[101010];
ll dp[101010][1010];
bool done[101010][1010];

ll rec(ll level, ll sum)
{
     if (sum == 0)
          return 1;
     if (level > n || sum < 0)
          return 0;

     if (done[level][sum])
          return dp[level][sum];

     done[level][sum] = 1;

     ll take = rec(level, sum - arr[level]);
     ll notTake = rec(level + 1, sum);

     return dp[level][sum] = take + notTake;
}
void solve()
{
     cin >> n >> k;
     for (ll i = 0; i < n; i++)
          cin >> arr[i];

     ll ans = rec(0, k);

     if (ans == 1e9)
          cout << "Given sum cannot be created\n";
     else
          cout << ans << "\n";
}

int main() {

#ifndef ONLINE_JUDGE
     freopen("Input.txt", "r", stdin);
     freopen("Output.txt", "w", stdout);
#endif

     ios_base::sync_with_stdio(false);
     cin.tie(nullptr);
     cout.tie(nullptr);

     ll t;
     t = 1;
     // cin >> t;
     while (t--)
     {
          solve();
     }

     return 0;
}
