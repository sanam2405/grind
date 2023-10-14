/*

All possible combinations
of k number out of numbers
[1,2,3,....,n]

*/

#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef long double ld;

ll n, k;
vector<ll> arr;
vector<ll> path;
vector<vector<ll>> ans;

void rec(ll level)
{
     if (level == n)
     {
          if (path.size() == k)
               ans.push_back(path);
          return;
     }

     path.push_back(arr[level]);
     rec(level + 1);
     path.pop_back();
     rec(level + 1);
}
void solve()
{
     cin >> n >> k;
     for (ll i = 0; i < n; i++)
          arr.push_back(i + 1);

     rec(0);

     for (auto &x : ans)
     {
          for (auto &y : x)
               cout << y << " ";
          cout << "\n";
     }
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
