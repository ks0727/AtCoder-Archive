#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
using ll = long long;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<int> s(n);
    rep(i,n) s[i+1] = s[i]^a[i];
    n++;
    ll ans = 0;
    rep(k,30){
        int one = 0;
        rep(i,n) if(s[i] >> k&1) one++;
        ans += one*ll(n-one)*(1<<k);
    }
    rep(i,n-1) ans -= a[i];
    cout << ans << endl;
    return 0;
}