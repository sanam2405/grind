/*

1. We solve this greedily by sorting the pairs 
2. An earlier finish times is more favourable than a late finish time
3. We pick the current element and then check for the rest

*/

#include<bits/stdc++.h>
int maximumActivities(vector<int> &start, vector<int> &finish) {
        
        int n = start.size();
        vector<pair<int,int>> times;
        int ans = 1;
        for(int i = 0; i < n; i++)
        {
            times.push_back({finish[i],start[i]});
        }
    
        sort(times.begin(),times.end());
        
        int currentEnd = times[0].first;
        for(int i = 1; i < n; i++)
        {
            if(times[i].second >= currentEnd)
            {
                    ans++;
                    currentEnd = times[i].first;
            }
        }
    
        return ans;
}
