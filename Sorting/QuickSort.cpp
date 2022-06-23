// Time complexity :  Average : O(nlog(n)) , Worst : O(n^2) 
// Space complexity : O(1)
#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef long double ld;

ll n;
vector<ll> arr;

ll partition(vector<ll> &a, ll start, ll end)
{
    ll pivot = a[end];
    ll pIndex = start;

    for (ll i = start; i < end; i++)
    {
        if (a[i] <= pivot)
        {
            swap(a[i], a[pIndex]);
            pIndex++;
        }
    }

    swap(a[pIndex], a[end]);
    return pIndex;
}

void quickSort(vector<ll> &a, ll start, ll end)
{
    if (start >= end)
        return;

    ll pIndex = partition(a, start, end);


    quickSort(a, start, pIndex - 1);
    quickSort(a, pIndex + 1, end);
}
void solve()
{
    cin >> n;
    arr.resize(n);

    for (ll i = 0; i < n; i++)
        cin >> arr[i];

    quickSort(arr, 0, n - 1);

    for (auto &x : arr)
        cout << x << " ";

}



int main() {

#ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll t;
    t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
