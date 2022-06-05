bool isValidParenthesis(string expression)
{
        stack<char> st;
    
        for(auto &x:expression)
        {
            if(st.empty() && (x==')'||x=='}'||x==']'))
               return false;
            if(st.empty())
                st.push(x);
            else
            {
                if(st.top()=='('&&x==')')
                   st.pop();
                else if(st.top()=='{'&&x=='}')
                   st.pop();
                else if(st.top()=='['&&x==']')
                   st.pop();
                else
                    st.push(x);
            }
        }
               
        return st.size()==0;
}
