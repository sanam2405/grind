#include<bits/stdc++.h>

int N;
vector<int> eachRow;
vector<vector<int>> board;
vector<vector<int>> ans;


bool canPlace(int row, int col)
{
    
    
    int i,j;
    
    i = row;j=col;
    while(i >= 0 && j >= 0)        // checking N-W diagonal
    {
        if(board[i--][j--]==1)
            return false;
    }
    
    i = row;j=col;
    while(i < N && j >= 0)        // checking S-W diagonal
    {
        if(board[i++][j--]==1)
            return false;
    }
    
    i = row;j=col;
    while(j >= 0)                // checking left cols
    {
        if(board[i][j--]==1)
            return false;
    }
    
    return true;
}
void rec(int col)
{
    if(col==N)
    {
        vector<int> temp;
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                temp.push_back(board[i][j]);
        
        ans.push_back(temp);
    }
    
    for(int row = 0; row < N; row++)
    {
        if(canPlace(row,col))
        {
            board[row][col] = 1;
            rec(col+1);
            board[row][col] = 0;
        }
    }
    
    return;
}
vector<vector<int>> solveNQueens(int n) {
    N = n;    
    eachRow.resize(n,0);
    for(int i = 0; i < n; i++)
    {
        board.push_back(eachRow);
    }
    
    rec(0);
    return ans;
}
