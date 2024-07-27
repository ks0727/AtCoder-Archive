#include <bits/stdc++.h>
using namespace std;
#include <atcoder/modint>
using namespace atcoder;
#define rep(i,n) for(int i=0;i<(n);++i)
using mint = modint998244353;

bool isPalind(string t){
    string nt = t;
    reverse(nt.begin(),nt.end());
    return t == nt;
};

int main(){
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    map<string,mint> dp;
    dp[""] = 1;
    rep(i,n){
        map<string,mint> old;
        swap(old,dp);
        for(auto [t,num] : old){
            if(s[i] == '?'){
                string nt = t + 'A';
                string ns = t + 'B';
                if(nt.size() < k) dp[nt] += num;
                else{
                    if(!isPalind(nt)){
                        nt.erase(nt.begin());
                        dp[nt] += num;
                    }
                } 
                if(ns.size() < k) dp[ns] += num;
                else{
                    if(!isPalind(ns)){
                        ns.erase(ns.begin());
                        dp[ns] += num;
                    }
                }
            }else{
                string nt = t + s[i];
                if(nt.size() < k) dp[nt] += num;
                else{
                    if(!isPalind(nt)){
                        nt.erase(nt.begin());
                        dp[nt] += num;
                    }
                } 
            }
        }
    }
    mint ans = 0;
    for(auto [t,num] : dp){
        ans += num;
    }
    cout << ans.val() << endl;
    return 0;
}