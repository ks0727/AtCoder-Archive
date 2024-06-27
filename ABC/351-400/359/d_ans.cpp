#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for(int i=0;i<(n);i++)
using mint = modint998244353;

bool isPalindrome(string s){
    string ns = s;
    reverse(ns.begin(),ns.end());
    return s == ns;
}

int main(){
    int n,k; cin >> n >> k;
    string s; cin >> s;
    map<string,mint> dp;
    dp[""] = 1;
    rep(i,n){
        map<string,mint> old;
        swap(dp,old);
        for(auto [t,num] : old){
            for(char c = 'A';c<='B';c++){
                if(s[i] != '?' && s[i] != c) continue;
                string nt = t+c;
                if(nt.size() == k && isPalindrome(nt)) continue;
                if(nt.size() == k) nt.erase(nt.begin());
                dp[nt] += num;
            }
        }
    }
    mint ans = 0;
    for(auto [t,num] : dp) ans += num;
    cout << ans.val() << endl;
    return 0;
}
