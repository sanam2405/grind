#include <bits/stdc++.h> 
/****************************************************************

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

*****************************************************************/


int countNodes(Node* head)
{
    int count = 0;
    while(head!=NULL)
    {
        head = head->next;
        count++;
    }
    
    return count;
}

Node* findMid(Node* head, int middle)
{
    int count = 1;
    while(head!=NULL)
    {
        head = head->next;
        count++;
        if(count==middle)
            return head;
    }
    
    return NULL;
}
Node *findMiddle(Node *head) {
        
        if(head==NULL)
            return NULL;
    
        int totalNodes = countNodes(head);
    
        int middle;
    
        middle=totalNodes/2+1;
        
        return findMid(head,middle);
}
