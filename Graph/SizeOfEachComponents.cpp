#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef long double ld;

ll n, m;
ll nodeVisited;
vector<vector<ll>> graph;
vector<ll> vis;
void dfs(ll node)
{
     vis[node] = 1;
     nodeVisited++;
     for (auto &x : graph[node])
     {
          if (!vis[x])
               dfs(x);
     }

}

void solve()
{
     cin >> n >> m;
     graph.clear();
     graph.resize(n + 1);
     vis.assign(n + 1, 0);
     for (ll i = 0; i < m; i++)
     {
          ll u, v;
          cin >> u >> v;
          graph[u].push_back(v);
          graph[v].push_back(u);
     }

     vector<ll> componentSize;

     for (ll node = 1; node <= n; node++)
     {
          nodeVisited = 0;
          if (!vis[node])
          {
               dfs(node);
               cout << nodeVisited << " ";
               componentSize.push_back(nodeVisited);
          }
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
