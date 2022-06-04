int uniqueElement(vector<int> arr, int n)
{
        int ans = arr[0];
    
        for(int i = 1; i < n; i++)
            ans = (ans^arr[i]);
    
        return ans;
}
