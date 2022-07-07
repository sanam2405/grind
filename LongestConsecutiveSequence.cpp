#include <bits/stdc++.h> 
int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
   
    int ans = 0;
    int cnt = 1;
    
    sort(arr.begin(),arr.end());
    
    for(int i = 1; i < n; i++)
    {
        if(arr[i]-arr[i-1]==1)
            cnt++;
        else if(arr[i]==arr[i-1])
            continue;
        else
        {
            ans = max(ans,cnt);
            cnt = 1;
        }
    }
     ans = max(ans,cnt);
    return ans;
}
