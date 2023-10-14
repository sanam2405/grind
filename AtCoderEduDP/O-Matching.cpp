#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef long double ld;

ll n;
ll MOD = 1e9+7;
ll C[22][22];
vector<vector<ll> > dp;

ll rec(ll men, ll women)
{

     if(women==(1<<n)-1)
          return 1LL;
     
     if(men>=n)
          return 0LL;;

     if(dp[men][women]!=-1)
          return dp[men][women];

     ll ans = 0;
     
     for(ll woman = 0; woman < n; woman++)
     {
          if((women&(1<<woman)))
               continue;

          if(C[men][woman]==1)
          {
               ll newWomen = (women|(1<<woman));
               ans += rec(men+1,newWomen);
               ans%=MOD;
          }
     }

     return dp[men][women] = ans%MOD;
}

void solve()
{
     cin >> n;
     for(ll i = 0; i < n; i++)
          for(ll j = 0; j < n; j++)
               cin >> C[i][j];
     dp.clear();
     dp.resize(n);
     for(ll i = 0; i < n; i++)
          dp[i].resize((1<<22),-1);

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