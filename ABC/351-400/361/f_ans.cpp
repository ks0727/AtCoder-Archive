#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using ll = long long;

ll calc(int b, ll n){
    ll l = 0, r=n+1;
    //l^b <= nとなればok
    while(r > l+1){
        ll mid = (l+r)/2;
        auto judge = [&]{
            ll x = 1;
            rep(i,b){
                if(n/x < mid) return false;
                x *= l;
            } 
            return x <= n;
        };
        if(judge()) l = mid;
        else r = mid;
    }
    return l-1; //1を除くために1を引く
}

int main(){
    ll n;
    cin >> n;
    const int M = 60;
    vector<ll> f(M);
    ll ans = 0;
    for(int b=M-1;b>=0;--b){
        f[b] = calc(b,n);
        for(int i=b*2;i<M;i+=b) f[b] -= f[i];
        ans += f[b];
    }
    cout << ans << endl;
    return 0;
}
