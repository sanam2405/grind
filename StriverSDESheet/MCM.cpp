int dp[111][111];
bool done[111][111];

int rec(int i, int j, vector<int> &arr)
{
    if(i+1==j)
        return 0;

    int mini = 1e9;
    if(done[i][j])
        return dp[i][j];
    done[i][j]=1;
    for(int k = i+1; k <= j-1; k++)
    {
        int steps = arr[i]*arr[k]*arr[j] + rec(i,k,arr) + rec(k,j,arr);
        mini = min(mini,steps);
    }
    return dp[i][j] = mini;
}
int matrixMultiplication(vector<int> &arr, int N)
{
   	for(int i = 0; i < 111; i++)
    {
        for(int j = 0; j < 111; j++)
        {
            dp[i][j]=0;
            done[i][j]=false;
        }
    }
    int ans = rec(0,N-1,arr);
    return ans;
}