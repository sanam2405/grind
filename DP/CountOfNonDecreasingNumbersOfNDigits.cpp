#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;

/*

Number of non-decreasing number
with N digits

*/

ll N;
ll dp[555][11];
bool done[555][11];


ll rec(ll idx, ll last)
{
    if(idx==N)
        return 1;

    if(done[idx][last])
        return dp[idx][last];

    done[idx][last]=1;
    ll ans = 0;

    for(ll i = 0; i <= last; i++)
    {
        ans += rec(idx+1,i);
    }

    return dp[idx][last] = ans;
}

void memclear()
{
    for(ll i = 0; i < 555; i++)
    {
        for(ll j = 0; j < 11; j++)
        {
                dp[i][j]=0;
                done[i][j]=false;
        }
    }
}

void solve()
{
    cin >> N;

    memclear();
    ll ans = rec(0,9);

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
     cin >> t;
     while (t--)
     {
          solve();
     }

     return 0;
}