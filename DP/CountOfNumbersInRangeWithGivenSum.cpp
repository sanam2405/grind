#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;

/*

Count of number in [A,B]
where sum of digits = K

*/


ll A,B,K;

ll dp[22][2][10010];
bool done[22][2][10010];

ll rec(ll idx, bool tight, int sumOfDigs, vector<ll> &N)
{
    if(idx==N.size())
        return sumOfDigs==0;

    if(done[idx][tight][sumOfDigs])
        return dp[idx][tight][sumOfDigs];


    done[idx][tight][sumOfDigs] = 1;
    ll range;
    if(tight)
        range = N[idx];
    else
        range = 9;


    ll ans = 0;
    for(ll i = 0; i <= range; i++)
    {
        bool newTight = tight && (N[idx]==i);
        ans += rec(idx+1,newTight,sumOfDigs-i,N);
    }

    return dp[idx][tight][sumOfDigs] = ans;

}

vector<ll> generate(ll x)
{
    vector<ll> N;
    while(x)
    {
        N.push_back(x%10);
        x/=10;
    }

    reverse(begin(N),end(N));
    return N;
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
    cin >> A >> B >> K;
    
    vector<ll> N_A = generate(A-1);
    vector<ll> N_B = generate(B);

    memclear();
    ll ansB = rec(0,1,K,N_B);
    memclear();
    ll ansA =  rec(0,1,K,N_A);

    cout << ansB-ansA << "\n";
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