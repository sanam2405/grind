#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef long double ld;

ll N;
vector<ll> A;
vector<ll> dp;

ll rec(ll level)
{
    if(level>=N)
        return 0;

    if(level==N-1)
        return 0;

    if(level==N-2)
        return abs(A[N-1]-A[N-2]);

    if(dp[level]!=-1)
        return dp[level];

    ll oneStep,twoStep;

    if(level+1 < N)
    oneStep = abs(A[level]-A[level+1])+rec(level+1);
    if(level+2 < N)
    twoStep = abs(A[level]-A[level+2])+rec(level+2);

    return dp[level] = min(oneStep,twoStep);
}

void solve()
{
     cin >> N;
     A.clear();
     A.resize(N);

     dp.clear();
     dp.resize(N,-1);

     for(ll i = 0; i < N; i++)
        cin >> A[i];

     ll ans = rec(0);

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