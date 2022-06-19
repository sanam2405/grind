/*

Number of ways to
create sum == k
where each item
may be taken multiple
times and printing
all the combinations


Here to avoid duplicate answers, we first sort the array and then take only the unique elements
*/

#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef long double ld;

ll n, k;
vector<ll> arr;
vector<ll> path;
vector<vector<ll>> ans;

void rec(ll level, ll sum)
{

     if (sum == 0)
     {
          ans.push_back(path);
          return;
     }

     for (ll i = level; i < n; i++)
     {
          if (i > level && arr[i] == arr[i - 1])
               continue;
          if (arr[i] > sum)
               break;
          path.push_back(arr[i]);
          rec(i + 1, sum - arr[i]);
          path.pop_back();
     }
}
void solve()
{
     cin >> n >> k;
     arr.resize(n);
     for (ll i = 0; i < n; i++)
          cin >> arr[i];

     sort(arr.begin(), arr.end());

     rec(0, k);


     for (auto &x : ans)
     {
          for (auto &y : x)
               cout << y << " ";
          cout << "\n";
     }
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
