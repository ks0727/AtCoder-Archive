#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main(){
    ll n;
    cin >> n;
    const int M = 1000001;
    ll ans = 0;
    for(int i=0;i<M;i++){
        ll x = (ll)i*i*i;
        if(x > n) break;
        if(x < 10) ans = x;
        string s = to_string(x);
        string t = s;
        reverse(t.begin(),t.end());
        if(s == t) ans = x;
    }
    cout << ans << endl;
    return 0;
}