#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using ll = long long;

int main(){
    int n,m;
    cin >> n >> m;
    vector<ll> x(m);
    rep(i,m) cin >> x[i];

    auto f = [&](int  l,int x, int T)->bool{
        ll res = min((ll)2*l+x,(ll)l+(ll)2*x);
        return res <= T;
    };

    ll tl = 0, tr = 1001001001;
    while(tr - tl > 1){
        ll tm = (tr+tl)/2;
        ll now = 0;
        rep(i,m){
            ll low = 0;
            ll high = i != m-1 ? x[i+1] - x[i]:n - x[i];
            ll l = x[i] - now - 1;
            ll r = max(tm-2*l,(tm-l)/2);
            now = x[i]+r;
        }
        if(now < n) tl = tm;
        else tr = tm;
    }
    cout << tr << endl;
    return 0;
}