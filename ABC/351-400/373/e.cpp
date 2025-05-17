#include <bits/stdc++.h>
using namespace std;
#include <atcoder/segtree>
using namespace atcoder;
#define rep(i,n) for(int i=0;i<n;++i)
using ll = long long;

ll op(ll a, ll b){
    return a+b;
}
ll e(){return 0;}
ll target;

int main(){
    int n,m; ll k;
    cin >> n >> m >> k;
    vector<ll> a(n);
    ll sum = 0;
    rep(i,n) cin >> a[i],sum+=a[i];
    vector<ll> b = a;
    sort(b.begin(),b.end());
    segtree<ll,op,e> seg(n);
    rep(i,n) seg.set(i,b[i]);
    ll rest = k - sum;
    vector<ll> ans(n);
    rep(i,n){
        //当選不可
        int p = upper_bound(b.begin(),b.end(),a[i]+rest) - b.begin();
        if(p < n-m){
            cout<< -1 << endl;
            continue;
        } 
        //当選可能
        ll left = -1, right = rest;
        while(right-left>1){
            ll mid = (right+left)/2;
            target = a[i]+mid;
            auto f = [&](ll x){
                return x < target;
            };
            int l = seg.min_left(n,f);
            cout << l << endl;
            if(l<n-m) left = mid;
            else{
                int u = n-l;
                if(u < 0){
                    left = mid;
                    continue;
                } 
                if(u-l >= 0 && seg.get(u-l) >= a[i]){
                    ll tsum = seg.prod(max(u-l-1,0),l);
                    
                    tsum -= a[i];
                    ll need = ll(u-l)*(a[i]+mid);
                    if(need-tsum<=rest-mid) left = mid;
                    else right = mid;
                }else{
                    ll tsum = seg.prod(u-l,l);
                    ll need = ll(u-l)*(a[i]+mid);
                    if(need-tsum <= rest-mid) left = mid;
                    else right = mid;
                }
            }
        }
        ans[i] = right;
    }
    return 0;
}
