#include<bits/stdc++.h>
int m,n;

bool canPlace(int row, int col, int ch, int board[9][9])
    {
            
            for(int i = 0; i < 9; i++)
            {
                if(board[i][col]==ch)
                    return false;
            }
        
            for(int i = 0; i < 9; i++)
            {
                if(board[row][i]==ch)
                    return false;
            }
        
            int subX = (row/3) * 3;
            int subY = (col/3) * 3;
        
            for(int i = 0; i < 3; i++)
            {
                for(int j = 0; j < 3; j++)
                {
                    if(board[subX+i][subY+j]==ch)
                        return false;
                }
            }
        
            return true;
}

bool rec(int board[9][9])
    {
                for(int i = 0; i < m; i++)
                {
                    for(int j = 0; j < n; j++)
                    {
                        if(board[i][j]==0)
                        {
                            for(int ch = 1; ch <= 9; ch++)
                            {
                                if(canPlace(i,j,ch,board))
                                {
                                    board[i][j] = ch;
                                    if(rec(board))
                                        return true;
                                    else
                                        board[i][j] = 0;
                                }
                            }
                            
                            return false;
                        }
                    }
                }
        
                return true;
    }
bool isItSudoku(int board[9][9]) {
        
        m = 9;
        n = 9;
        return rec(board);
}
