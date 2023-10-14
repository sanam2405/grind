#include<bits/stdc++.h>
class Queue {
    
    stack<int> a;
    stack<int> b;
    
    public:
    Queue() {
    }

    void enQueue(int val) {        // O(1)
        a.push(val);
    }

    int deQueue() {                // O(n)
        
        if(a.size()==0)
            return -1;
        
        while(a.size() > 1)
        {
            b.push(a.top());
            a.pop();
        }
        
        int front = a.top();
        a.pop();
        while(!b.empty())
        {
            a.push(b.top());
            b.pop();
        }
        return front;
    }

    int peek() {                    // O(n)
        
        if(a.empty())
            return -1;
        
        while(a.size() > 1)
        {
            b.push(a.top());
            a.pop();
        }
        
        int front = a.top();
        while(!b.empty())
        {
            a.push(b.top());
            b.pop();
        }
        
        return front;
    }

    bool isEmpty() {                // O(1)
        
        return a.size()==0;
    }
};
