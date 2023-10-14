#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef long double ld;

string a, b;

ll dp[1010][1010];
bool done[1010][1010];

ll rec(ll i, ll j)
{
    if (i >= a.length() || j >= b.length())
        return 0;

    if (done[i][j])
        return dp[i][j];

    done[i][j] = 1;

    if (a[i] == b[j])
        return dp[i][j] = 1 + rec(i + 1, j + 1);
    else
        return dp[i][j] = max(rec(i + 1, j), rec(i, j + 1));
}
void solve()
{
    cin >> a >> b;

    ll ans = rec(0, 0);

    cout << ans << "\n";

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
