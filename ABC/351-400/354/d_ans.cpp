#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

ll f(ll a, ll b){
    ll ra = a%4; a-= ra;
    ll rb = b%2; b-= rb;
    ll res = a*b;
    if(rb == 1) res += a;
    if(ra >= 1){
        res += b*3/2;
        if(rb == 1) res += 2;
    }
    if(ra >= 2){
        res += b*3/2;
        if(rb == 1) res += 1;
    }
    if(ra >= 3) res += b/2;
    return res;
}

int main(){
    ll a,b,c,d; cin >> a >> b >> c >> d;
    a += 1e9; b += 1e9; 
    c += 1e9; d += 1e9; 
    ll ans = f(c,d) - f(a,b) - f(c,b) + f(a,b);
    cout << ans << endl;
    return 0;
}