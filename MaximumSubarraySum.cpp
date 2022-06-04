#include <bits/stdc++.h> 
typedef long long int ll;
long long maxSubarraySum(int arr[], int n)
{
    ll sum = 0;
    ll maxi = INT_MIN;
    
    for(ll i = 0; i < n; i++)
    {
        sum+=arr[i];
        if(sum > maxi)
            maxi = sum;
        if(sum < 0)
            sum = 0;
    }
    
    if(maxi < 0)
        return 0;
    else
    return maxi;
}
