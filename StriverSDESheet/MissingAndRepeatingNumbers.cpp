#include <bits/stdc++.h> 

typedef long long int ll;
pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	pair<int,int> ans;
   
    ll totalSum = 0;
    
    sort(arr.begin(),arr.end());
    
    int missing,repeating;
    
    for(int i = 1; i < n; i++)
    {
        if(arr[i]==arr[i-1])
        {
            repeating=arr[i];
            break;
        }
    }
    
    for(int i = 0; i < n; i++)
        totalSum+=(long long)arr[i];
    
    ll expectedSum = (1LL*n*(n+1))/2;
    
    missing = expectedSum-(totalSum-repeating);
    
    ans.first = missing;
    ans.second = repeating;
    
    return ans;
}
