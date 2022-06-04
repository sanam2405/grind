#include <bits/stdc++.h> 
void setZeros(vector<vector<int>> &matrix)
{
        vector<pair<int,int>> zeroPos;
    
        int m = matrix.size();
        int n = matrix[0].size();
    
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(matrix[i][j]==0)
                    zeroPos.push_back({i,j});
            }
        }
    
        for(auto &x:zeroPos)
        {
            int row = x.first;
            int col = x.second;
            
            for(int i = 0; i < m; i++)
            {
                matrix[i][col] = 0;
            }
            
            
            for(int i = 0; i < n; i++)
            {
                matrix[row][i] = 0;
            }
        }
}
