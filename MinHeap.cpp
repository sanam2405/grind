vector<int> minHeap(int n, vector<vector<int>>& q) {
    
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> ans;
    int i = 0;
    while(n--)
    {
        int x = q[i][0];
        
        if(x==0)
        {
            pq.push(q[i][1]);
        }
        else
        {
            int currentMin = pq.top();
            pq.pop();
            ans.push_back(currentMin);
        }
        
        i++;
    }
    
    return ans;
}
