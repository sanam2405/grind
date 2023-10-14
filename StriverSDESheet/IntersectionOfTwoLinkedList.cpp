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

int findIntersection(Node *firstHead, Node *secondHead)
{
        Node* a = firstHead;
        Node* b = secondHead;
    
       int A = 0;
       int B = 0;
    
        while(firstHead!=secondHead)
        {
            
            if(firstHead==secondHead)
                return firstHead->data;
            
            firstHead = firstHead->next;
            secondHead = secondHead->next;
            
            if(firstHead==NULL)
            {
                    firstHead=b;
                    A++;
            }
            
            if(secondHead==NULL)
            {
                    secondHead=a;
                    B++;
            }
            
            if(A>=2&&B>=2)
                return -1;
        }
    
    return firstHead->data;
}
