#include <bits/stdc++.h>

vector<int> generateLPS(string str) {
    int n = str.size();
    vector<int> lps(n, 0);
    for(int i = 1; i < n; i++) {
        int len = lps[i - 1];
        
        while(len > 0 && str[i] != str[len]) len = lps[len - 1];
        
        if(str[i] == str[len]) len++;
        
        lps[i] = len;
    }
    
    return lps;
}
int minCharsforPalindrome(string s) {
    string rev = s;
    reverse(rev.begin(), rev.end());
    
    string str = s + '$' + rev;
    
    auto lps = generateLPS(str);
    
    return s.size() - lps.back();
}
