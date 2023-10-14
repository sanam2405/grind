#include<bits/stdc++.h>

void insert(int top, stack<int> &st)
{
    if(st.empty() || top > st.top())
    {
        st.push(top);
        return;
    }
    
    int temp = st.top();
    st.pop();
    insert(top,st);
    st.push(temp);
}
void sortStack(stack<int> &stack)
{
	if(stack.size() <= 1)
        return;
    
    int top = stack.top();
    stack.pop();
    sortStack(stack);
    insert(top,stack);
   
}
