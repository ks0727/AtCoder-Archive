#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;
using mint = modint998244353;

string ntob(ll x){
    string res = "";
    while (x){
        res += x%2+'0';
        x /= 2;
    }
    while(res.size() <= 60) res+='0';
    reverse(res.begin(),res.end());
    return res;
};

int main(){
    ll n,m;
    cin >> n >> m;
    string ns = ntob(n);
    string ms = ntob(m);
    
    return 0;
}