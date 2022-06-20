#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef long double ld;

string str;
ll n;
bool dp[1010][1010];
bool done[1010][1010];

bool rec(ll i, ll j)
{
     if (i >= j)
          return true;
     if (done[i][j])
          return dp[i][j];

     done[i][j] = 1;

     if (str[i] == str[j])
          return dp[i][j] = rec(i + 1, j - 1);
     else
          return dp[i][j] = false;
}

void solve()
{

     cin >> str;
     n = str.length();

     bool ans = rec(0, n - 1);

     if (ans)
          cout << "Palindrome\n";
     else
          cout << "Not Palindrome\n";
}



int main() {

#ifndef ONLINE_JUDGE
     freopen("Input.txt", "r", stdin);
     freopen("Output.txt", "w", stdout);
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
