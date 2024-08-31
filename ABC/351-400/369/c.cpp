#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using ll = long long;

ll f(ll x){
    ll res = x*(x+1)/2-x - (x-1); 
    return res;
}

int main(){
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    if( n == 1){
        cout << 1 << endl;
        return 0;
    }else if( n == 2){
        cout << 3 << endl;
        return 0;
    }
    vector<ll> dif(n-1);
    rep(i,n-1) dif[i] = a[i+1] - a[i];
    ll cnt = 0;
    ll ans = n;
    ans += n-1;
    rep(i,n-2){
        if(dif[i] == dif[i+1]){
            cnt++;
            if(cnt >= 1) ans += cnt;
        }else{
            cnt = 0;
        }
    }
    cout << ans << endl;
    return 0;
}