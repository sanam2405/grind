#include<bits/stdc++.h>
int getMedian(vector<vector<int>> &matrix)
{
        vector<int> all;
        int m = matrix.size();
        int n = matrix[0].size();
                       
        for(int i = 0; i  < m; i++)
             for(int j = 0; j < n; j++)
                       all.push_back(matrix[i][j]);

        sort(all.begin(),all.end());
                       
        int total = all.size();
                       
        if(total&1)
            {
                int mid = total/2;
                return all[mid];
            }
                       
        else
            {
                int mid = total/2;
                int high = all[mid];
                int low = all[mid-1];
                           
                return (low+high)/2;
            }
}
