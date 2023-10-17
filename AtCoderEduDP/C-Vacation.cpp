#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef long double ld;

ll N;
vector<vector<ll> > P;
vector<vector<ll> > dp;

ll rec(ll level, ll task)
{
    if(level >= P.size())
        return 0LL;

    if(dp[level][task]!=-1)
        return dp[level][task];

    ll ans = 0LL;
    
    if(task==0)
    {
        ans = P[level][task] + max(rec(level+1,1),rec(level+1,2));
    }

    else if(task==1)
    {
        ans = P[level][task] + max(rec(level+1,0),rec(level+1,2));
    }

    else
    {
        ans = P[level][task] + max(rec(level+1,0),rec(level+1,1));
    }

    return dp[level][task] = ans;
}

void solve()
{
     cin >> N;
     P.resize(N);

     for(ll i = 0; i < P.size(); i++)
        P[i].resize(3);

    for(ll i = 0; i < P.size(); i++)
        cin >> P[i][0] >> P[i][1] >> P[i][2];

    dp.resize(N);
    for(ll i = 0; i < dp.size(); i++)
        dp[i].resize(3,-1);

    ll ans = -1e12;
    ans = max(ans,rec(0,0));
    ans = max(ans,rec(0,1));
    ans = max(ans,rec(0,2));

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