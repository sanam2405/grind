#include<bits/stdc++.h>

bool check(int newX, int newY, int n, int m)
{
    if(newX >= 0 && newX < n && newY >= 0 && newY < m)
        return true;
    else
        return false;
}
int minTimeToRot(vector<vector<int>>& grid, int n, int m)
{
        int totalOranges = 0;
        int currentRotten = 0;
        int time = 0;
    
        int dx[] = {0,0,-1,1};
        int dy[] = {-1,1,0,0};
    
        queue<pair<int,int>> q;
    
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 1 || grid[i][j] == 2)
                    totalOranges++;
                if(grid[i][j] == 2)
                {
                    q.push({i,j});
                    currentRotten++;
                }
                    
            }
        }
    
    
        while(!q.empty())
        {
             int size = q.size();
             while(size--)
             {
                 pair<int,int> current = q.front();
                 q.pop();
                 
                 for(int i = 0; i < 4; i++)
                 {
                     int newX = current.first+dx[i];
                     int newY = current.second+dy[i];
                     
                     if(check(newX,newY,n,m) && grid[newX][newY]==1)
                     {
                         q.push({newX,newY});
                         grid[newX][newY] = 2;
                     }
                 }
             }
             currentRotten+=q.size();
             if(q.size())
             time++;
        }
    
        if(currentRotten==totalOranges)
            return time;
        else
            return -1;
        
}
