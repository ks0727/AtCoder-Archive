#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main(){
    int n,m;
    cin >> n >> m;
    fenwick_tree<ll> d(n+1); //imos法を用いるために長さをn+1にしておく
    auto add = [&](int l,int r, ll x){
        d.add(l,x);
        d.add(r,-x);
    };
    rep(i,n){
        int a;
        cin >> a;
        add(i,i+1,a);
    }
    rep(mi,m){
        int b;
        cin >> b;
        ll x = d.sum(0,b+1);
        add(b,b+1,-x);

        ll c = x/n; x %= n;
        add(0,n,c);
        b++;
        if(b+x<n){
            add(b,b+x,1);
        }else{
            add(b,n,1);
            add(0,b+x-n,1);
        }
    }
    rep(i,n){
        ll ans = d.sum(0,i+1);
        cout << ans << ' ';
    }
    cout << endl;
    return 0;
}