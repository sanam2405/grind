#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef long double ld;

class ListNode
{
public:
    ll val;
    ListNode *next;
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

ListNode *hasCycle(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return NULL;

    ListNode *fast;
    ListNode *slow;

    fast = head;
    slow = head;

    while (fast->next->next != NULL && slow->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (slow == fast)
            break;
    }

    if (slow->next == NULL || fast->next->next == NULL)
        return NULL;

    ListNode *meeting = slow;

    slow = head;

    while (slow != meeting)
    {
        slow = slow->next;
        meeting = meeting->next;
    }

    return slow;
}

ListNode *createLinkedList(vector<ll> &arr, ll pos)
{
    ListNode *current = new ListNode(0);
    ListNode *head = current;
    // map<ll,ListNode*>
    ListNode *loopStart; // stores where the tail points
    for (ll i = 0; i < arr.size(); i++)
    {
        current->next = new ListNode(arr[i]);
        current = current->next;
        if (i == pos)
        {
            loopStart = current;
        }
        if (i == arr.size() - 1)
        {
            if (pos != -1)
                current->next = loopStart;
            else
                current->next = NULL;
            break;
        }
    }

    ListNode *LLHead = head->next;

    return LLHead;
}

void solve()
{
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for (ll i = 0; i < n; i++)
        cin >> arr[i];
    ll pos;
    cin >> pos;

    ListNode *head = createLinkedList(arr, pos);

    ListNode *cycleNode;

    cycleNode = hasCycle(head);

    if (cycleNode == NULL)
    {
        cout << "NO CYCLE";
    }
    else
    {
        cout << cycleNode->val << "\n";
    }
}

int main()
{

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