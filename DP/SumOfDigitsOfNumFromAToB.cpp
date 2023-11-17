#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;

/*

Sum of digits of all numbers 
from A to B inclusive

*/


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

ll rec(ll idx, bool tight, ll sum, vector<ll> &N)
{
    if(idx==N.size())
    {
        return sum;
    }

    ll range;

    if(tight)
        range = N[idx];
    else
        range = 9;

    ll ans = 0;

    for(ll i = 0; i <= range; i++)
    {       
        bool newTight = tight && (i == N[idx]);         
        ans += rec(idx+1,newTight,sum+i,N);
    }

    return ans;
}
void solve()
{
    ll A,B;
    cin >> A >> B;
    
    vector<ll> N_A = generate(A - 1);
    ll ansA = rec(0, 1, 0, N_A);

    vector<ll> N_B = generate(B);
    ll ansB = rec(0, 1, 0, N_B);

    cout << ansB - ansA;    

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