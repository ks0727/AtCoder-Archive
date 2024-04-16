#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
using ll = long long;

int main(){
    ll L,R; cin >> L >> R;
    vector<pair<ll,ll> > ans;
    auto f = [&](auto f,ll l, ll r)->void{
        if(L <= l && r <= R){
            ans.emplace_back(l,r);
            return;
        }
        ll c = (l+r)>>1; //(l+r)/2
        if(L < c) f(f,l,c);
        if(c < R) f(f,c,r);
    };
    f(f,0,1ll<<60);
    cout <<ans.size() << endl;
    for(auto[l,r] : ans) cout << l << ' ' << r << endl;
    return 0;
}