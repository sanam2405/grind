#include<bits/stdc++.h>
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    int n = vertex;
    vector<int> adj[n];
    
    for(int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<int> ans;
    vector<int> vis(n+1,0);
    
    
    for(int i = 0; i < n; i++)
    {
          if(!vis[i])
          {
               queue<int> q;
               q.push(i);
               vis[i] = 1;
               sort(adj[i].begin(),adj[i].end());
                while(!q.empty())
                {
                    int node = q.front();
                    q.pop();
                    ans.push_back(node);

                    for(auto &x:adj[node])
                    {
                        if(!vis[x])
                        {
                            q.push(x);
                            vis[x]=1;
                        }
                    }
                }
          }
    }
    return ans;
    
    
}
