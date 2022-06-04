vector<int> ans;
vector<int> subset;

void rec(int level, vector<int> &nums)
{
    if(level==nums.size())
    {
        int sum = 0;
        for(auto &x:subset)
            sum+=x;
      
        ans.push_back(sum);
        return;
    }
    
    subset.push_back(nums[level]);
    rec(level+1,nums);
    subset.pop_back();
    rec(level+1,nums);
}
vector<int> subsetSum(vector<int> &num)
{
        
        ans.clear();
        subset.clear();
        rec(0,num);
        sort(ans.begin(),ans.end());
    
        return ans;
}
