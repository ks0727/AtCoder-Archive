#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main(){
    int n; string s;
    cin >> n >> s;
    vector<int> c(n);
    rep(i,n) cin >> c[i];
    rep(i,n){
        if(i%2 == 1) s[i] ^= '1'^'0';
    }
    ll ans = 1e18;
    rep(bi,2){
        vector<ll> l(n+1),r(n+1);
        rep(i,n){
            l[i+1] = l[i];
            if(s[i] == '1') l[i+1] += c[i];
        }
        for(int i=n-1;i>=0;i--){
            r[i] = r[i+1];
            if(s[i] == '0') r[i] += c[i];
        }
        for(int i=1;i<(n);i++){
            ans = min(ans,l[i]+r[i]);
        }
        rep(i,n) s[i] ^= '0'^'1';
    }
    cout << ans << endl;
}