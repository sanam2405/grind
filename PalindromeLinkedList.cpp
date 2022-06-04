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
#include<bits/stdc++.h>
vector<int> v;
void helper(LinkedListNode<int>* head)
{
 	while(head!=NULL)
    {
        v.push_back(head->data);
        head = head->next;
    }
}
bool isPalindrome(LinkedListNode<int> *head) {
	
    v.clear();
    helper(head);
    int i = 0, j = v.size()-1;
    while(i<j)
    {
        if(v[i]!=v[j])
            return false;
        i++;j--;
    }
    
    return true;
}
