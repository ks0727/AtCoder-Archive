#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;
int main(){
    int n;
    cin >> n;
    vector<vector<ll> > g(n,vector<ll>(n));
    rep(i,n-1){
        rep(j,n-i){
            ll value;
            cin >> value;
            g[i].emplace_back(value);
            g[j].emplace_back(value);
        }
    }
    vector<bool> seen(n);
    int repeat = n*(n-1)/2;
    rep(i,repeat){
        rep(j,g[i].size()){
            int value = g[i][j];
            
        }
    }
}