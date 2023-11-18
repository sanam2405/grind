#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;

ll rec(ll idx, ll even, ll leadingZeros, ll tight, vector<ll> &N)
{
     if(idx==N.size())
     {
          if(leadingZeros==0)
          return 1;
          else
          return 0;
     }

     ll range;
     
     if(tight)
          range = N[idx];
     else
          range = 9;

     ll ans = 0;
     if(even)
          {
               if(leadingZeros)
                         ans+=rec(idx+1,1,1,0,N);
               
               vector<ll> odds = {1,3,5,7,9};

               for(auto &odd:odds)
               {
                    ll newTight = tight && (range==odd);
                    if(odd <= range)
                    ans+=rec(idx+1,0,0,newTight,N);     
                    
               }  
          }
     else
          {
               vector<ll> evens = {0,2,4,6,8};

               for(auto &even:evens)
               {
                    ll newTight = tight && (range==even);
                    if(even <= range)
                    ans+=rec(idx+1,1,0,newTight,N);     
               }
          }
     
     return ans;
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
void solve()
{
     ll L,R;
     cin >> L >> R;

     vector<ll> N_L = generate(L-1);
     vector<ll> N_R = generate(R);

     ll ansR = rec(0,1,1,1,N_R);
     ll ansL = rec(0,1,1,1,N_L);

     // cout << ansR << " " << ansL << "\n";
     ll ans = ansR - ansL;

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