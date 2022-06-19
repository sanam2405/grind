/*

Number of ways to
create sum == k
where each item
may be taken multiple
times and printing
all the combinations

*/

#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef long double ld;

ll n, k;
vector<ll> arr;
vector<ll> path;
vector<vector<ll>> ans;

void rec(ll level, ll sum)
{

     if (sum == 0)
     {
          ans.push_back(path);
          return;
     }

     if (level == n)
     {
          if (sum == 0)
               ans.push_back(path);
          return;
     }

     if (arr[level] <= sum)
     {
          path.push_back(arr[level]);
          rec(level, sum - arr[level]);
          path.pop_back();
          rec(level + 1, sum);
     }
     else
          rec(level + 1, sum);
}
void solve()
{
     cin >> n >> k;
     arr.resize(n);
     for (ll i = 0; i < n; i++)
          cin >> arr[i];

     rec(0, k);

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
