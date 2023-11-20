#include <bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
typedef long double ld;
 
ll dp[22][11][2][2];
bool done[22][11][2][2];
map<vector<ll>,ll> rp;

ll rec(ll idx, ll last, ll leadingZeros, ll tight, vector<ll> &N)
{
     if(idx==(long long)N.size())
          return 1LL;
     
     vector<ll> states = {idx,last,leadingZeros,tight};

     if(rp.find(states)!=rp.end())
          return rp[states];

     // if(last!=-1 && done[idx][last][leadingZeros][tight])
     //      return dp[idx][last][leadingZeros][tight];
 
     done[idx][last][leadingZeros][tight]=1;
 
     ll range = (tight)? N[idx] : 9;
 
     ll ans = 0;
 
     for(ll i = 0; i <= range; i++)
     {
          ll newTight = tight && (i==N[idx]);
          if(i==last&&leadingZeros==0)
               continue;
          ans += rec(idx+1,i,leadingZeros&&(i==0),newTight,N);
     } 
     
     return rp[states] = ans; 
     // return dp[idx][last][leadingZeros][tight] = ans;
}
 
vector<ll> generate(ll n)
{
     vector<ll> N;
     while(n)
     {
          N.push_back(n%10);
          n/=10;
     }
     reverse(begin(N),end(N));
     return N;
}
 
void memclear()
{
     for(ll i = 0; i < 22; i++)
          for(ll j = 0; j < 11; j++)
               for(ll k = 0; k < 2; k++)
                    for(ll l = 0; l < 2; l++)
                    {
                         dp[i][j][k][l]=0;
                         done[i][j][k][l]=false;
                    }
}
 
void solve()
{
    ll L,R;
    cin >> L >> R;
 
    vector<ll> N_L = generate(L-1);
    vector<ll> N_R = generate(R);
 
    // memclear();
    ll ansL = rec(0,-1,1,1,N_L);
    // memclear();
    rp.clear();
    ll ansR = rec(0,-1,1,1,N_R);
 
    ll ans = ansR-ansL;
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