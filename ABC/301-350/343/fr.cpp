#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for(int i=0;i<n;++i)
using ll = long long;

struct S{
    ll sx,mx, cnt_sx,cnt_mx;
    S(ll sx=-2, ll mx=-1,ll cnt_sx=0,ll cnt_mx=0):sx(sx),mx(mx),cnt_sx(cnt_sx),cnt_mx(cnt_mx){}
};

S op(S a, S b){
    set<ll> st;
    st.insert(a.sx);
    st.insert(a.mx);
    st.insert(b.sx);
    st.insert(b.mx);
    S res = S(-2,-1,0,0);
    ll mx = *st.rbegin();
    if(mx == a.mx){
        res.mx = a.mx;
        res.cnt_mx += a.cnt_mx;
    }
    if(mx == b.mx){
        res.mx = b.mx;
        res.cnt_mx += b.cnt_mx;
    }
    st.erase(mx);
    if(st.size() == 0) return res;
    ll sx = *st.rbegin();
    if(sx == a.mx){
        res.sx = a.mx;
        res.cnt_sx += a.mx;
    }
    if(sx == b.mx){
        res.sx = b.mx;
        res.cnt_sx += b.cnt_mx;
    }
    if(sx == a.sx){
        res.sx = a.sx;
        res.cnt_sx += a.cnt_sx;
    }
    if(sx == b.sx){
        res.sx = b.sx;
        res.cnt_sx += b.cnt_sx;
    }
    return res;
}
S e(){
    S res = S(-2,-1,0,0);
    return res;
}
int main(){
    int n,q;
    cin >> n >> q;
    segtree<S,op,e> seg(n);
    rep(i,n){
        ll a; cin >> a;
        seg.set(i,S(-2,a,0,1));
    }
    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            int p; ll x;
            cin >> p >> x;
            seg.set(p,S(-2,x,0,1));
        }else{
            int l,r;
            l--; r--;
            S ans = seg.prod(l,r+1);
            cout << ans.cnt_sx << endl;
        }
    }
    return 0;
}