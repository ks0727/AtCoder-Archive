#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using ll = long long;

int modpow(ll x, ll k, int mod){
    if(k == 0) return 1%mod;
    ll res = modpow(x,k/2,mod);
    res = (res*res)%mod;
    if(k %2 == 1) res = (res*x)%mod;
    return res;
}

int main(){
    int n;
    cin >> n;
    ll k;
    cin >> k;
    vector<int> p(n);
    rep(i,n) cin >> p[i],p[i]--;

    //サイクルの検出
    vector<int> ans(n);
    vector<bool> used(n);
    rep(i,n){
        if(!used[i]){
            int v = i;
            vector<int> vs;
            while(!used[v]){
                used[v] = true;
                vs.push_back(v);
                v = p[v];
            }
            int c = vs.size();
            int m = modpow(2,k,c);
            rep(j,c){
                ans[vs[j]] = vs[(j+m)%c];
            }
        }
    } 
    rep(i,n) cout << ans[i] +1 << ' '; cout << endl;
    return 0;
}