
class Solution{
public:
    
    pair<int,string> dp[33][33];
    
    pair<int,string> rec(int i, int j, int arr[])
    {
        if(i+1==j)
        {
            string str = "";
            str += 'A' + i;
            return {0,str};
        }
        
        if(dp[i][j].first!=-1)
        return dp[i][j];
        
        int ans = 1e9;
        string str = "";
        for(int k = i+1; k <= j-1; k++)
        {
            int currentScore = arr[i]*arr[k]*arr[j];
            pair<int,string> leftScore = rec(i,k,arr);
            pair<int,string> rightScore = rec(k,j,arr);
            
            if(currentScore+leftScore.first+rightScore.first < ans)
            {
                ans = currentScore+leftScore.first+rightScore.first;
                str = "(" + leftScore.second + rightScore.second + ")";
            }
        }
        
        return dp[i][j] = {ans,str};
    }
    string matrixChainOrder(int matrix[], int n){
        
        
        for(int i = 0; i < 33; i++)
            for(int j = 0; j < 33; j++)
                {
                    dp[i][j] = {-1,""};
                }
        
        string ans = rec(0,n-1,matrix).second;
        
        return ans;
    }
}