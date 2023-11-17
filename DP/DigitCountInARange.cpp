#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;

/*

Given a range [A,B]
Find the number of occurrence 
of digit D in the numbers 
in the range [A,B]

*/

ll A,B;
ll D;

ll dp[22][2][10010];
bool done[22][2][10010];

vector<ll> generate(ll n)
{
    vector<ll> N;
    N.clear();
    while(n)
    {
        N.push_back(n%10);
        n/=10;
    }
    reverse(begin(N),end(N));
    return N;
}

ll rec(ll idx, ll tight, ll cntDigs, vector<ll> &N)
{
    if(idx==N.size())
    return cntDigs;

    if(done[idx][tight][cntDigs])
        return dp[idx][tight][cntDigs];

    done[idx][tight][cntDigs]=1;

    ll range;
    if(tight)
        range = N[idx];
    else
        range = 9;
    ll ans = 0;
    for(ll i = 0; i <= range; i++)
    {
        ll newTight = tight&&(N[idx]==i);
        ans += rec(idx+1,newTight,cntDigs+(i==D),N);
    }
    
    return dp[idx][tight][cntDigs] = ans;
}

void memclear()
{
    for(ll i = 0; i < 22; i++)
    {
        for(ll j = 0; j < 2; j++)
        {
            for(ll k = 0; k < 10010; k++)
            {
                dp[i][j][k]=0;
                done[i][j][k]=false;
            }
        }
    }
}

void solve()
{
    cin >> A >> B;
    cin >> D;

   
    vector<ll> N_A = generate(A - 1);
    ll ansA = rec(0, 1, 0, N_A);

    memclear();

    vector<ll> N_B = generate(B);
    ll ansB = rec(0, 1, 0, N_B);

    cout << ansB - ansA << "\n";    

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
        memclear();
        solve();
     }

     return 0;
}