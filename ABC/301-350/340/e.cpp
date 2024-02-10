#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

ll op(ll a,ll b){
    return min(a,b);
}
ll e(){
    return ll(1e18);
}
ll mapping(ll f,ll x){
    return f+x;
}
ll composition(ll f,ll g){
    return f+g;
}
ll id(){
    return 0;
}
int main(){
    int n,m;
    cin >> n >> m;
    lazy_segtree<ll,op,e,ll,mapping,composition,id> seg(n);
    rep(i,n){
        ll x;
        cin >> x;
        seg.set(i,x);
    }
    rep(i,m){
        int b;
        cin >> b;
        ll balls = seg.get(b);
        ll all = balls/n;
        ll rest = balls%n;
        seg.set(b,0);
        seg.apply(0,n,all);
        if(b+1+rest >= n){
            seg.apply(b+1,n,1);
            seg.apply(0,rest-(n-b-1),1);
        }else{
            seg.apply(b+1,b+1+rest,1);
        }
    }
    rep(i,n) cout << seg.get(i) << ' ';
    cout << endl;
    return 0;
}