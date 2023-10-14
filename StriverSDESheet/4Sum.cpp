/*

Approach 1 : Use four loops. O(n^4)
Approach 2 : Use three loops and seach for the fourth number. O(n^3log(n))
Approach 3 : Use two loops and apply two sum on the rest. O(n^3)

*/

#include <bits/stdc++.h> 
string fourSum(vector<int> arr, int target, int n) {
        
        sort(arr.begin(),arr.end());
    
        for(int i = 0; i < n-2; i++)
        {
            for(int j = i+1; j < n-2; j++)
            {
                  int low = j+1, high = n-1;
                
                    while(low < high)
                    {
                        if(arr[i]+arr[j]+arr[low]+arr[high] > target)
                            high--;
                        else if(arr[i]+arr[j]+arr[low]+arr[high] < target)
                            low++;
                        else
                            return "Yes";
                    }
            }
        }
    
        return "No";
}
