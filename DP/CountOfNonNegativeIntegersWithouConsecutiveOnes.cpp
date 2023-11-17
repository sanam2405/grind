#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;

/*

Number of non-negative integers
without consecutive ones in 
binary representation in the range [0,N]

*/



int dp[33][3][3];
bool done[33][3][3];

int rec(int idx, int tight, int last, vector<int> &N)
{
    if(idx==N.size())
        return 1;

    if(done[idx][tight][last])
    return dp[idx][tight][last];

    done[idx][tight][last]=1;

    int range;
    if(tight)
    range = N[idx];
    else
    range = 1;
    int ans = 0;
    for(int i = 0; i <= range; i++)
    {
        int newTight = tight && (i==N[idx]);
        if(last!=1 || i!=1)
        ans += rec(idx+1,newTight,i,N);
    }

    return dp[idx][tight][last] = ans;
}

void memclear()
{
    for(ll i = 0; i < 33; i++)
    {
        for(ll j = 0; j < 33; j++)
        {
            for(ll k = 0; k < 3; k++)
                {
                    dp[i][j][k]=0;
                    done[i][j][k]=false;
                }
        }
    }
}

void solve()
{
    ll n;
    cin >> n;
    vector<int> N;
    while(n)
    {
        N.push_back(n%2);
        n/=2;
    }

    reverse(begin(N),end(N));
    
    memclear();
    ll ans = rec(0,1,0,N);

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