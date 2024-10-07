#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using ll = long long;
using P = pair<int,int>;
struct Machine{
    int a,p;
};

int main(){
    int n; ll x;
    cin >> n >> x;
    vector<Machine> s(n),t(n);
    rep(i,n){
        cin >> s[i].a >> s[i].p;
        cin >> t[i].a >> t[i].p;
        if(t[i].a *s[i].p > t[i].p*s[i].a) swap(s[i],t[i]); //常にsが効率が良い方だとする
    }
    auto f = [&](int m){
        ll cost = 0;
        rep(i,n){
            ll now = 1e18;
            rep(j,s[i].a){
                ll k  = max(m-t[i].a*j,0); //kはsで作る必要がある個数
                k = (k+s[i].a-1)/s[i].a;
                now = min(now,t[i].p*j+s[i].p*k);
            }
            cost += now;
            if(cost > x) return false;
        }
        return cost <= x;
    };
    int l = 0, r = x*100+1;
    while(r-l>1){
        int mid = (l+r)/2;
        if(f(mid)) l = mid;
        else r = mid; 
    }
    cout << l << endl;
    return 0;
}