#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main(){
    ll a,m,l,r;
    cin >> a >> m >> l >> r;
    ll k1 = (r-a)/m;
    ll k2 = (l-a)/m;
    ll ans = 0;
    if(l > a){
        ans = k1-k2;
        if((l-a)%m == 0)ans++;
    }else if(r < a){
        ans = k1-k2;
        if((r-a)%m == 0) ans++;
    }else{
        ans = k1-k2+1;
    }
    cout << ans << endl;
    return 0;
}