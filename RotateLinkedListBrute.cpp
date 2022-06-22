#include <bits/stdc++.h> 
/********************************

    Following is the class structure of the Node class:
    
    class Node
    {
    	public:
    	    int data;
    	    Node *next;
    	    Node(int data)
    	    {
    	        this->data = data;
    	        this->next = NULL;
    	    }
    };

********************************/

vector<int> arr;

void helper(Node* head)
{
    while(head!=NULL)
        {
             arr.push_back(head->data);
             head = head->next;
        }
        
    return;
}

Node *rotate(Node *head, int k) {
        
        arr.clear();
        helper(head);
        int size = arr.size();
        vector<int> sorted(size);
    
        for(int i = 0; i < size; i++)
        {
            sorted[(i+k)%size] = arr[i];
        }
    
        Node* dummy = new Node(0);
        Node* ptr = dummy;
    
        for(int i = 0; i < size; i++)
        {
            ptr->next = new Node(sorted[i]);
            ptr = ptr->next;
        }
    
        return dummy->next;
}
