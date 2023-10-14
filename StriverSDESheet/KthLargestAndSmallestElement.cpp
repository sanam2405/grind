#include<bits/stdc++.h>
vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
	    sort(arr.begin(),arr.end());
        int kSmall = k-1;
        int kLarge = n-k;
        
        vector<int> ans = {arr[kSmall],arr[kLarge]};
    
        return ans;
}
