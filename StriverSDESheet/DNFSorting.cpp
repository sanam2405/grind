#include <bits/stdc++.h> 
void sort012(int *arr, int n)
{
        int low = 0, mid = 0, high = n-1;
    
        // All elements left side of low will be 0
        // All element right side of high will be 2
    
        while(mid <= high)
        {
            if(arr[mid] == 0)
            {
                swap(arr[mid],arr[low]);
                mid++;
                low++;
            }
            
            else if(arr[mid] == 1)
            {
                mid++;
            }
            
            else if(arr[mid] == 2)
            {
                swap(arr[mid],arr[high]);
                high--;
            }
        }
}
