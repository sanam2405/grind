#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef long double ld;


class ListNode
{
    public:
        ll val;
        ListNode* next;
        ListNode(ll x)
        {
            val = x;
            next = NULL;
        }
        ListNode()
        {
            val = -1;
            next = NULL;
        }
};

ListNode* reverseLL(ListNode* head)
{
    if(head==NULL)
        return NULL;

    if(head->next==NULL)
    return head;

    ListNode* d = head;
    ListNode* p = head->next;

    ListNode* rp = reverseLL(p);
    p->next = d;
    d->next = NULL;

    return rp;
}

ListNode* createLinkedList(vector<ll> &arr)
{
    ListNode* current = new ListNode(0);
    ListNode* head = current;
    for(ll i = 0; i < arr.size(); i++)
    {
        current->next = new ListNode(arr[i]);
        current = current->next;
        if(i==arr.size()-1)
        {
            current->next = NULL;
            break;
        }
    }

    ListNode* LLHead = head->next;
    
    return LLHead;
}

void solve()
{
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for(ll i = 0; i < n; i++)
        cin >> arr[i];
    
    ListNode* head = createLinkedList(arr);   

    ListNode* reverseLLHead;

    reverseLLHead = reverseLL(head);

    ListNode* current = reverseLLHead;
    while(current!=NULL)
    {
        cout << current->val << " ";
        current = current->next;
    }
}


int main() {

#ifndef ONLINE_JUDGE
     freopen("input.txt", "r", stdin);
     freopen("output.txt", "w", stdout);
#endif

     ios_base::sync_with_stdio(false);
     cin.tie(nullptr);
     cout.tie(nullptr);

     ll t;
     t = 1;
    //  cin >> t;
     while (t--)
     {
          solve();
     }

     return 0;
}