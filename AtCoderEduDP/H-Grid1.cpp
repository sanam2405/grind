#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef long double ld;

ll N,M;
ll MOD = 1e9+7;

vector<vector<char> > G;
vector<vector<ll> > dp;

ll rec(ll i, ll j)
{
    if(i>=N||j>=M)
        return 0;

    if(i==N-1&&j==M-1)
        return 1;

    if(G[i][j]=='#')
        return 0;

    if(dp[i][j]!=-1)
        return dp[i][j];

    ll right = 0, down = 0;

    if(j+1 < M)
    right = rec(i,j+1)%MOD;
    if(i+1 < N)
    down = rec(i+1,j)%MOD;

    return dp[i][j] = (right%MOD+down%MOD)%MOD;
}
void solve()
{
     cin >> N >> M;
     G.resize(N);
     for(ll i = 0; i < N; i++)
        G[i].resize(M);

     for(ll i = 0; i < N; i++)
        for(ll j = 0; j < M; j++)
            cin >> G[i][j];

    dp.resize(N);
     for(ll i = 0; i < N; i++)
        dp[i].resize(M,-1);

    ll ans = rec(0,0);

    cout << ans%MOD << "\n";
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