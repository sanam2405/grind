#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef long double ld;

ll n, m;
vector<vector<ll>> graph;
vector<ll> color;
vector<ll> parent;
vector<ll> cycle;
bool isCyclePresent = false;

/*

1 is the initial color
2 is the color when we are exploring
3 is the color when we have explored

*/

void dfs(ll node, ll par)
{
     parent[node] = par;
     color[node] = 2;

     for (auto &x : graph[node])
     {
          if (x == parent[node])
               continue;
          if (color[x] == 1)              // node--->x is forward edge
          {
               dfs(x, node);
          }

          else if (color[x] == 2)         // node--->x is back edge
          {
               if (isCyclePresent == false)
               {
                    ll temp = node;
                    while (temp != x)
                    {
                         cycle.push_back(temp);
                         temp = parent[temp];
                    }
                    cycle.push_back(temp);
               }

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
     parent.assign(n + 1, 0);
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
               dfs(node, 0);
          }
     }

     if (isCyclePresent)
          cout << "Cycle is present!\n";
     else
          cout << "Cycle is not present!\n";

     for (auto &x : cycle)
          cout << x << " ";
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
