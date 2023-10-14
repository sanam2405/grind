#include<bits/stdc++.h>
vector<int> nextGreater(vector<int> &arr, int n) {
            
    vector<int> nge(n,-1);
    stack<int> st;
    st.push(arr[n-1]);
    for(int i = n-2; i >= 0; i--)
    {
        while(!st.empty() && st.top() <= arr[i])
            st.pop();
        if(st.size())
        {
            nge[i] = st.top();
            st.push(arr[i]);
        }
        else
        {
            nge[i] = -1; //already -1 so this is optional
            st.push(arr[i]);
        }
    }
    
    return nge;
}
