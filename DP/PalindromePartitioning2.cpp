/*

Minimum number of cuts
needed for palindrome
partitioning of str

*/

#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef long double ld;

ll n;
string str;

ll dp[2020];
bool done[2020];

bool checkPalin(ll low, ll high)
{
     while (low < high)
     {
          if (str[low++] != str[high--])
               return false;
     }

     return true;
}

ll rec(ll level)
{
     if (level == n)
          return 0;

     if (done[level])
          return dp[level];

     done[level] = 1;
     ll ans = INT_MAX;
     for (ll i = level; i < n; i++)
     {
          if (checkPalin(level, i))
          {
               ll cost = 1 + rec(i + 1);
               ans = min(ans, cost);
          }
     }

     return dp[level] = ans;
}
void solve()
{
     cin >> str;
     n = str.length();

     ll ans = rec(0) - 1;

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
