#include <bits/stdc++.h> 
int uniqueSubstrings(string input)
{
        int ans = 1;
        int n = input.length();
        int tail = 0, head = -1;
        
        map<char,int> m;
    
        while(tail<n)
        {
            while(head+1<n&&m[input[head+1]]==0)
            {
                head++;
                m[input[head]]++;
            }
            
            ans = max(head-tail+1,ans);
            
            if(tail<=head)
            {
                m[input[tail]]--;
                if(m[input[tail]]==0)
                    m.erase(m[input[tail]]);
                tail++;
            }
            else
            {
                tail++;
                head=tail-1;
            }
        }    
    
        return ans;
        
}
