#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef long double ld;

ll n, m;
vector<vector<ll>> graph;
vector<ll> color;
bool isCyclePresent = false;

/*

1 is the initial color
2 is the color when we are exploring
3 is the color when we have explored

*/

void dfs(ll node)
{
     color[node] = 2;

     for (auto &x : graph[node])
     {
          if (color[x] == 1)              // node--->x is forward edge
          {
               dfs(x);
          }

          else if (color[x] == 2)         // node--->x is back edge which implies a cycle is present
          {
               isCyclePresent = true;
          }

          else if (color[x] == 3)         // node--->x is cross edge
          {
               // DO NOTHING
          }
     }

     color[node] = 3;

}

void solve()
{
     cin >> n >> m;
     graph.clear();
     graph.resize(n + 1);
     color.assign(n + 1, 1);
     for (ll i = 0; i < m; i++)
     {
          ll u, v;
          cin >> u >> v;
          graph[u].push_back(v);
     }


     for (ll node = 1; node <= n; node++)
     {
          if (color[node] == 1)
          {
               dfs(node);
          }
     }

     if (isCyclePresent)
          cout << "Cycle is present!";
     else
          cout << "Cycle is not present!";
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
