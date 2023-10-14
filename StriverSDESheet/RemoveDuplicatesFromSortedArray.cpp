#include<bits/stdc++.h>
int removeDuplicates(vector<int> &arr, int n) {
        
    
    int ans = 1;
    
    for(int i = 1; i < n; i++)
    {
            if(arr[i]==arr[i-1])
                continue;
            else
                ans++;
    }
    
    return ans;
}
