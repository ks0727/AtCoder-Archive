#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main(){
    ll sx,sy; cin >> sx >> sy;
    ll tx,ty; cin >> tx >> ty;
    auto f = [&](ll &x, ll &y){
        if(y%2 == 0 && x % 2 == 1) x--;
        if(y%2 == 1 && x % 2 == 0) x--;
    };
    f(sx,sy);
    f(tx,ty);
    //cout <<sx << endl;
    //cout << sy << endl;
    //cout << tx << endl;
    //cout << ty << endl;
    ll dx = abs(sx-tx);
    ll dy = abs(sy-ty);
    ll ans = dy;
    if((dx-dy)/2 > 0) ans += (dx-dy)/2;
    cout << ans << endl;
    return 0;
}