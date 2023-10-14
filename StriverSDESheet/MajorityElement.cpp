#include <bits/stdc++.h> 
int findMajorityElement(int arr[], int n) {
        
        // Moore's Voting Algorithm. O(n) TC O(1) SC
        int target = n/2;
        int count = 0;
        int candidate = 0;
    
        for(int i = 0; i < n; i++)
        {
            if(count==0)
            {
                candidate = arr[i];
            }
            
            if(candidate==arr[i])
                count++;
            else
                count--;
        }
        
        count = 0;
        
        for(int i = 0; i < n; i++)
        {
            if(arr[i]==candidate)
                count++;
        }
    
        if(count > target)
            return candidate;
        else
            return -1;
}
