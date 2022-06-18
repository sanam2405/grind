/*

1. Create a dummy node pointing to head
2. Create fast and slow pointers pointing to the dummy node
3. Move the fast pointer by K units to the front
4. Move the slow and fast pointer together by 1 unit till fast->next == NULL or fast reaches the last node
5. slow now points to the (K-1)th node. Do slow->next = slow->next->next

*/

#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

LinkedListNode<int>* removeKthNode(LinkedListNode<int> *head, int K)
{
    
        if(head==NULL || K==0)
            return head;
    
        LinkedListNode<int> *dummy = new LinkedListNode<int>(0);
        LinkedListNode<int> *fast;
        LinkedListNode<int> *slow;
    
        dummy->next = head;
        fast = dummy;
        slow = dummy;
    
        for(int i = 1; i <= K; i++)
            fast = fast->next;
    
        while(fast->next!=NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
    
        slow->next = slow->next->next;
    
        return dummy->next;
}
