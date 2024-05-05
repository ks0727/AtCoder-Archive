#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;
int main(){
    int n;
    cin >> n;
    vector<int> a(n),b(n);
    rep(i,n) cin >> a[i] >> b[i];
    ll s = 0;
    rep(i,n) s += a[i];
    ll ans = -1;
    rep(i,n){
        ans = max(ans,s-a[i]+b[i]);
    }
    cout << ans << endl;
    return 0;
}