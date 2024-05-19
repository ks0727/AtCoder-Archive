#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;
using P = pair<ll,ll>;
int main(){
    ll a,b,c,d;
    cin >> a >> b >> c >> d;
    auto f = [&](ll x,ll y)->ll{
        ll res = 0;
        res += (x/4)*(y/4)*8;
        ll sx = (x/4)*4;
        ll sy = (y/4)*4;
        ll rx = x%4;
        ll ry = y%4;
        if(rx == 1){
            res += 3*sy;
        }else if(rx == 2){
            res += 6*sy;
        }else if(rx == 3){
            res += 7*sy;
        }
        if(ry == 1){
            res += 2*sx;
        }else if(ry == 2){
            res += 4*sx;
        }else if(rx == 3){
            res += 6*sx;
        }
        res *= 2;
        map<P,ll> rest; 
        rest[P(1,1)] = 2;
        rest[P(1,2)] = 3;
        rest[P(1,3)] = 5;
        rest[P(2,1)] = 3;
        rest[P(2,2)] = 6;
        rest[P(2,3)] = 9;
        rest[P(3,1)] = 3;
        rest[P(3,2)] = 7;
        rest[P(3,3)] = 10;
        res += rest[P(rx,ry)];
        return res;
    };
    a += 1000000000;
    b += 1000000000;
    c += 1000000000;
    d += 1000000000;
    ll ans = f(c,d) - f(a,d) - f(c,b) + f(a,b);
    cout << ans << endl;
    return 0;
}