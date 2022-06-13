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

Node *firstNode(Node *head)
{
        if(head==NULL||head->next==NULL)
            return NULL;
       Node* fast = head;
       Node* slow = head;
       bool flag = false;
       while(fast->next!=NULL && fast->next->next != NULL)
       {
           
           slow = slow->next;
           fast = fast->next->next;
           if(fast==slow)
           {
               flag = true;
               break;
           }
       }
    
        if(flag)
        {
            
      
        slow = head;
    
        while(slow!=fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
    
        return slow;
           
        }
    
        return NULL;
}
