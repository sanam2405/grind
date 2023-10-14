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

Node *addTwoNumbers(Node *head1, Node *head2)
{
        Node* dummy = new Node(0);
        Node* ptr = dummy;
    
        int carry = 0;
    
        while(head1!=NULL&&head2!=NULL)
        {
            int dig = carry+head1->data+head2->data;
            carry = dig/10;
            dig=dig%10;
            ptr->next = new Node(dig);
            ptr = ptr->next;
            head1=head1->next;
            head2=head2->next;
        }
    
        while(head1!=NULL)
        {
            int dig = carry+head1->data;
            carry = dig/10;
            dig=dig%10;
            ptr->next = new Node(dig);
            ptr = ptr->next;
            head1=head1->next;
        }
    
    
        while(head2!=NULL)
        {
            int dig = carry+head2->data;
            carry = dig/10;
            dig=dig%10;
            ptr->next = new Node(dig);
            ptr = ptr->next;
            head2=head2->next;
        }
    
        if(carry)
            ptr->next = new Node(carry);
    
        return dummy->next;
}
