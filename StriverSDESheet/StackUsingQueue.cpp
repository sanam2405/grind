#include<bits/stdc++.h>
class Stack {
    
    queue<int> a;
    queue<int> b;
    int Top;
    
   public:
    Stack() {
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {                    // O(1)
        
        return a.size();
    }

    bool isEmpty() {                    // O(1)
        
        return a.size()==0;
    }

    void push(int element) {            // O(1)
        
        a.push(element);
        Top = element;
    }

    int pop() {                         // O(n)
        
        int poppingElement = Top;
        if(a.size()==0)
            return -1;
        
        while(a.size() > 1)
        {
            b.push(a.front());
            a.pop();
        }
        
        a.pop();
        
        while(!b.empty())
        {
            Top = b.front();
            a.push(b.front());
            b.pop();
        }
        
        return poppingElement;
    }

    int top() {                          // O(1)
        
        if(a.size()==0)
            return -1;
        
        return Top;
    }
};
