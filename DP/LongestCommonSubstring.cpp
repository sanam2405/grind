#include <bits/stdc++.h> 

string A,B;
map<vector<int>,int> dp;
int M,N;
int rec(int i, int j, int count)
    {
        
        if(i==M||j==N)
        return count;

        vector<int> states;
        states.push_back(i);
        states.push_back(j);
        states.push_back(count);

        if(dp.find(states)!=dp.end())
        return dp[states];


        if(A[i]==B[j])
            count = rec(i+1,j+1,count+1);

        count = max({count,rec(i+1,j,0),rec(i,j+1,0)});
        return dp[states]=count;


    }

int lcs(string &str1, string &str2){

	A = str1;
	B = str2;
    M = A.length();
    N = B.length();
    dp.clear();
	int ans = rec(0,0,0);

	return ans;
}
