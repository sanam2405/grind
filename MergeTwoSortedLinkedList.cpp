#include <bits/stdc++.h> 
/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
        Node<int>* dummy = new Node<int>(-1);
        Node<int>* ptr = dummy;
        while(first!=NULL && second!=NULL)
        {
            if(first->data < second->data)
            {
                ptr->next = new Node<int>(first->data);
                ptr = ptr->next;
                first = first->next;
            }
            
            else if(first->data > second->data)
            {
                ptr->next = new Node<int>(second->data);
                ptr = ptr->next;
                second = second->next;
            }
            
            else
            {
                ptr->next = new Node<int>(first->data);
                ptr = ptr->next;
                ptr->next = new Node<int>(second->data);
                ptr = ptr->next;
                first = first->next;
                second = second->next;
            }
        }
    
        while(first!=NULL)
        {
                ptr->next = new Node<int>(first->data);
                ptr = ptr->next;
                first = first->next;
        }
    
    
        while(second!=NULL)
        {
                ptr->next = new Node<int>(second->data);
                ptr = ptr->next;
                second = second->next;
        }
    
        return dummy->next;
}
