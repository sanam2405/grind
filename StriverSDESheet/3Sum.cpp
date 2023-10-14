#include <bits/stdc++.h> 
vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
        
            vector<vector<int>> ans;
            set<vector<int>> st;
            sort(arr.begin(),arr.end());
            for(int i = 0; i < n-2; i++)
            {
                int target = K-arr[i];
                
                int low = i+1, high = n-1;
                
                while(low < high)
                {
                    if(arr[low]+arr[high] > target)
                        high--;
                    else if(arr[low]+arr[high] < target)
                        low++;
                    else
                    {
                        vector<int> triplet;
                        triplet.push_back(arr[i]);
                        triplet.push_back(arr[low]);
                        triplet.push_back(arr[high]);
                     
                        st.insert(triplet);
                        low++;
                        high--;
                    }
                }
            }
    
            for(auto &x:st)
            {
                ans.push_back(x);
            }
    
           return ans;
}
