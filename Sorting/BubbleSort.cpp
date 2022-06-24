// Time complexity : O(n^2)
// Space complexity : O(1)
#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef long double ld;

ll n;
vector<ll> arr;


void bubbleSort(vector<ll> &a)
{
    ll n = a.size();

    for (ll i = 0;  i < n; i++)
    {
        for (ll j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
        }
    }
}

void solve()
{
    cin >> n;
    arr.resize(n);

    for (ll i = 0; i < n; i++)
        cin >> arr[i];

    bubbleSort(arr);

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
