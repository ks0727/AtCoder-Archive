#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main(){
    ll x;
    cin >> x;
    ll ans = 0;
    if(x >= 0) ans = (x+10-1)/10;
    else ans = x/10;
    cout << ans << endl;
    return 0;
}