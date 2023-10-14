#include <bits/stdc++.h> 

typedef long long int ll;

vector<ll> a;
ll ans;

void merge(vector<ll> left, vector<ll> right, vector<ll> &a)
{
    ll m = (long long)left.size();
    ll n = (long long)right.size();
    
    ll i = 0, j = 0, idx = 0;
    
    while(i<m&&j<n)
    {
        if(left[i]<right[j])
        {
            a[idx] = left[i];
            idx++;i++;
        }
        
        else if(left[i]>right[j])
        {
            a[idx] = right[j];
            ans+= m-i;            // if the right[j] is less than left[i], 
                                  // then all the elements from [i.....m-1] is greater than
                                  // right[j]
            idx++;j++;                
        }
        else
        {
            ans+= m-i-1;          // if the right[j] is equal to left[i], 
                                  // then all the elements from [i+1.....m-1] is greater than
                                  // right[j]
            a[idx] = left[i];
            idx++;
            a[idx] = right[j];
            idx++;
            i++;
            j++;
        }
    }
    
    while(i<m)
    {
        a[idx++] = left[i++];
    }
    
    while(j<n)
    {
        a[idx++] = right[j++];
    }
}

void mergeSort(vector<ll> &a)
{
    ll n = a.size();
    
    if(n < 2)
        return;
    
    vector<ll> left;
    vector<ll> right;
    
    ll mid;
    
    mid = n/2;
    
    for(ll i = 0; i < mid; i++)
        left.push_back(a[i]);
    
    for(ll i = mid; i < n; i++)
        right.push_back(a[i]);
    
    mergeSort(left);
    mergeSort(right);
    
    merge(left,right,a);
}
long long getInversions(long long *arr, int n){
    
    for(int i = 0; i < n; i++)
        a.push_back(arr[i]);
    
    ans = 0;
    
    mergeSort(a);
    
    return ans;
}
