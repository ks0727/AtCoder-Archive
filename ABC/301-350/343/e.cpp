#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;
ll op(ll a, ll b){
    return max(a,b);
}
ll e(){
    return 0;
}
int main(){
    int n,q;
    cin >> n >> q;
    segtree<ll,op,e> seg(n);
    map<ll,set<int> > mp;
    rep(i,n){
        ll x;
        cin >> x;
        mp[x].insert(i);
        seg.set(i,x);
    }
    rep(qi,q){
        int type;
        cin >> type;
        if(type == 1){
            int p; ll x;
            cin >> p >> x;
            p--;
            ll y = seg.get(p);
            mp[y].erase(p);
            if(mp[y].size() == 0) mp[y].clear();
            seg.set(p,x);
            mp[x].insert(p);
        }else{
            int l,r;
            cin >> l >> r;
            l--;
            ll mx = seg.prod(l,r);
            auto key = mp.lower_bound(mx);
            for(auto idx = key;idx != mp.begin();idx--){
                if(idx == key) continue;
                auto ex = idx->second.lower_bound(l);
                
            }
        }
    }
    return 0;
}