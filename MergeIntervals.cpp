#include <bits/stdc++.h> 
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
            int n = intervals.size();
            vector<vector<int>> ans;
            pair<int,int> current;
    
            sort(intervals.begin(),intervals.end());
    
            current.first = intervals[0][0];
            current.second = intervals[0][1];
    
    
            for(int i = 1; i < n; i++)
            {
                if(current.second >= intervals[i][0] && current.second <= intervals[i][1])
                    current.second = intervals[i][1];
                else if(current.second >= intervals[i][0] && current.second > intervals[i]
                        [1])
                    current.second = current.second;
                else
                {
                    vector<int> temp = {current.first,current.second};
                    ans.push_back(temp);
                    current.first = intervals[i][0];
                    current.second = intervals[i][1];
                }
            }
    
    
            vector<int> temp = {current.first,current.second};
            ans.push_back(temp);
    
            return ans;
}
