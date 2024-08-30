#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using ll = long long;
using ull = unsigned long long;
mt19937_64 rng(58);

const ll mod = 1e16+61;
const ll M = 200005;

int main(){
    int n,q;
    cin >> n >> q;
    vector<ll> a(n),b(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    vector<ll> hash(M);
    rep(i,M) hash[i] = rand();
    vector<ll>  ha(n+1),hb(n+1);
    for(int i=0;i<n;++i){
        ha[i+1] = (ha[i] + hash[a[i]])%mod;
        hb[i+1] = (hb[i] + hash[b[i]])%mod;
    }
    while(q--){
        int la,ra,lb,rb;
        cin >> la >> ra >> lb >> rb;
        la--; lb--;
        if((ha[ra]-ha[la]+mod)%mod == (hb[rb]-hb[lb]+mod)%mod) cout << "Yes" << '\n';
        else cout << "No" << '\n';
    }
    return 0;
}