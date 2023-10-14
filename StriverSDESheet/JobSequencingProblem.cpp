#include <bits/stdc++.h> 


// INTUITION : We need to do the jobs with maximum profit as late or as close to its deadline 
//             as we can
bool cmp(vector <int> a,vector<int> b)
{
     return a[1]>b[1];
}
int jobScheduling(vector<vector<int>> &jobs)
{
    sort(jobs.begin(),jobs.end(),cmp);
    int n=jobs.size();
    int maxDeadline=-1;
    for (int i=0;i<n;i++)
     maxDeadline=max(jobs[i][0],maxDeadline);
     int profit=0;
     vector<int> ans(maxDeadline+1,-1);     
     
     for (int i=0;i<n;i++)
     {
         int currDeadline=jobs[i][0];
         int currProfit=jobs[i][1];
         for (int k=currDeadline;k>0;k--)
         {
             if(ans[k]==-1)
             {
                 profit+=currProfit;
                 ans[k]=1;
                 break;
             }
         }
     }
    return profit;
}
