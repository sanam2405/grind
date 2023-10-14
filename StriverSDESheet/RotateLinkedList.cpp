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

int getLength(Node* head)
{
    int len = 0;
    while(head!=NULL)
    {
        head = head->next;
        len++;
    }
    
    return len;
}

Node *rotate(Node *head, int k) {
        
        // 1 2 3 4 5 6 ---->original
        // 5 6 1 2 3 4 ----> rotated by two places
    
        Node* ptr = head;
        int len = getLength(head);        // length of the LL
        k%=len;
        k = len-k;                        // node which needs to be set to NULL
        len--;                            // we want to reach the last node
        while(len--)
        {
            ptr = ptr->next;
        }
        
        ptr->next = head;                // ptr is now the last node, assign current end to 
                                         // head
        
        while(k--)
            ptr = ptr->next;             // ptr moves to the new last node
    
        head = ptr->next;                // make the node next to the new last node head
                                         // set the next of the new last node to null
        ptr->next = NULL;
    
        return head;
}
