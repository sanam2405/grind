#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3333;  
typedef long long int ll;

string s, t;
ll dp[MAXN][MAXN];
bool done[MAXN][MAXN];

ll rec(ll i, ll j) {
    if (i >= s.length() || j >= t.length())
        return 0;

    if (done[i][j])
        return dp[i][j];

    done[i][j] = true;
    ll ans = 0;
    if (s[i] == t[j])
        ans = 1 + rec(i + 1, j + 1);
    else
        ans = max(rec(i + 1, j), rec(i, j + 1));

    return dp[i][j] = ans;
}

string printLCS(ll i, ll j) {
    if (i >= s.length() || j >= t.length())
        return "";

    if (s[i] == t[j])
        return s[i] + printLCS(i + 1, j + 1);
    else if (dp[i + 1][j] < dp[i][j + 1])
        return printLCS(i , j + 1);
    else
        return printLCS(i + 1, j);
}

void solve() {
    cin >> s >> t;

    fill(*dp, *dp + MAXN * MAXN, -1);
    fill(*done, *done + MAXN * MAXN, false);

    ll longestLength = rec(0, 0);
    // cout << longestLength << "\n";
    string ans = printLCS(0, 0);

    cout << ans << "\n";
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
     // cin >> t;
     while (t--)
     {
          solve();
     }

     return 0;
}