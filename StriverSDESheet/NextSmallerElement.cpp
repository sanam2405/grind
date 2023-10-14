#include<bits/stdc++.h>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    vector<int> nse(n,-1);
    stack<int> st;
    st.push(arr[n-1]);
    
    for(int i = n-2; i >= 0; i--)
    {
        while(!st.empty() && st.top() >= arr[i])
            st.pop();
        
        if(st.size())
        {
            nse[i] = st.top();
            st.push(arr[i]);
        }
        else
        {
            nse[i] = -1; // optional since all elements are -1
            st.push(arr[i]);
        }
    }
    
    return nse;
}
