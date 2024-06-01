#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
using ll = long long;

int main(){
    ll a,b,c,d; cin >> a >> b >> c >> d;
    a += 1e9; b+= 1e9;
    c += 1e9; d+= 1e9;
    auto f = [&](ll x,ll y){
        ll res = 0;
        res += (x/4)*(y/2)*8;
        ll rx = x%4; ll ry = y%2;
        if(ry == 0){
            if(rx == 1){
                res += 3*(y/2);
            }else if(rx == 2){
                res += 6*(y/2);
            }else if(rx == 3){
                res += 7*(y/2);
            }
            return res;
        }else{
            res += 4*(x/4);
            if(rx == 1){
                res += 3*(y/2);
                res += 2;
            }else if(rx == 2){
                res += 6*(y/2);
                res += 3;
            }else if(rx == 3){
                res += 7*(y/2);
                res += 3;
            }
            return res;
        }
    };
    ll ans = f(c,d)-f(c,b)-f(a,d)+f(a,b);
    cout << ans << endl;
    return 0;
}