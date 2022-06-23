// Time complexity : O(nlog(n)) 
// Space complexity : O(n)
#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef long double ld;

ll n;
vector<ll> arr;

void merge(vector<ll> left, vector<ll> right, vector<ll> &a)
{
    ll m = left.size();
    ll n = right.size();

    ll i = 0, j = 0, idx = 0;

    while (i < m && j < n)
    {
        if (left[i] < right[j])
        {
            a[idx] = left[i];
            i++; idx++;
        }


        else if (left[i] > right[j])
        {
            a[idx] = right[j];
            j++; idx++;
        }

        else
        {
            a[idx] = left[i];
            idx++;
            a[idx] = right[j];
            idx++;
            i++;
            j++;
        }
    }

    while (i < m)
    {
        a[idx++] = left[i++];
    }


    while (j < n)
    {
        a[idx++] = right[j++];
    }
}

void mergeSort(vector<ll> &a)
{
    ll n = a.size();

    if (n < 2)
        return;

    ll mid = n / 2;

    vector<ll> left;
    vector<ll> right;

    for (ll i = 0; i < mid; i++)
        left.push_back(a[i]);
    for (ll i = mid; i < n; i++)
        right.push_back(a[i]);

    mergeSort(left);
    mergeSort(right);
    merge(left, right, a);
}
void solve()
{
    cin >> n;
    arr.resize(n);

    for (ll i = 0; i < n; i++)
        cin >> arr[i];

    mergeSort(arr);

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
