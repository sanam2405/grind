#include<bits/stdc++.h>

vector<vector<int>> ans;
vector<int> comp;
void dfs(int node,vector<int> adj[], vector<int> &vis)
{
    vis[node] = 1;
    comp.push_back(node);
    
    for(auto &x:adj[node])
    {
        if(!vis[x])
            dfs(x,adj,vis);
    }
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    vector<int> adj[V];
    vector<int> vis(V+1,0);
    
    for(int i = 0; i < edges.size(); i++)
    {
            int u =  edges[i][0];
            int v = edges[i][1];
        
            adj[u].push_back(v);
            adj[v].push_back(u);
    }
    
    for(int i = 0; i < V; i++)
    {    
        if(!vis[i])
        {   
            comp.clear();
            dfs(i,adj,vis);
            ans.push_back(comp);
        }
    }
    
    return ans;
}
