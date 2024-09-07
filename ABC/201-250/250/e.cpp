#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
mt19937_64 rng(58);
using ll = long long;
const ll mod = 1e16+61;

int main(){
    int n; cin >> n;
    vector<ll> a(n),b(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    map<ll,ll> hash;
    rep(i,n) if(!hash.count(a[i])) hash[a[i]] = rng();
    rep(i,n) if(!hash.count(b[i])) hash[b[i]] = rng();

    vector<ll> ha(n+1),hb(n+1);
    set<ll> sa,sb;
    rep(i,n){
        if(sa.count(a[i])){
            ha[i+1] = ha[i];
        }else{
            ha[i+1] = (ha[i]^hash[a[i]]);
            sa.insert(a[i]);
        }
        if(sb.count(b[i])){
            hb[i+1] = hb[i];
        }else{
            hb[i+1] = (hb[i]^hash[b[i]]);
            sb.insert(b[i]);
        }
    }
    int q;
    cin >> q;
    while(q--){
        int x,y;
        cin >> x >> y;
        if(ha[x] == hb[y]){
            cout << "Yes" << '\n'; 
        }else{
            cout << "No" << '\n';
        }
    }
    return 0;
}