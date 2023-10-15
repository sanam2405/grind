#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef long double ld;

ll N,W;
vector<vector<ll> > A;
vector<vector<ll> > dp;

ll rec(ll level, ll remainingWeight)
{
    if(remainingWeight <= 0)
        return 0;

    if(level >= N)
        return 0;

    if(dp[level][remainingWeight]!=-1)
        return dp[level][remainingWeight];

    ll take=0, notTake=0;

    if(A[level][0] <= remainingWeight)
    {
        take = A[level][1]+rec(level+1,remainingWeight-A[level][0]);
    }

    notTake = rec(level+1,remainingWeight);

    return dp[level][remainingWeight] = max(take,notTake);
}

void solve()
{
     cin >> N >> W;
     A.clear();
     A.resize(N);

     for(ll i = 0; i < N; i++)
        A[i].resize(W);

     dp.clear();
     dp.resize(N+1);

     for(ll i = 0; i < N; i++)
        dp[i].resize(W+1,-1);

     for(ll i = 0; i < N; i++)
        for(ll j = 0; j < 2; j++)
            cin >> A[i][j];

     ll ans = rec(0,W);

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