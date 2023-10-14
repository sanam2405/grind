#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef long double ld;

ll n;
vector<ll> v;
vector<ll> path;
vector<vector<ll>> ans;

void rec(ll level)
{
     if (level == n)
     {
          ans.push_back(path);
          return;
     }

     path.push_back(v[level]);
     rec(level + 1);
     path.pop_back();
     rec(level + 1);
}

void solve()
{
     cin >> n;

     v.resize(n);
     for (ll i = 0; i < n; i++)
          cin >> v[i];

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
