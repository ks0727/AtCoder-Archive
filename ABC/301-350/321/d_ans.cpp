#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;
int main(){
    int n,m,p;
    cin >> n >> m >> p;
    vector<int> a(n),b(m);
    rep(i,n) cin >> a[i];
    rep(i,m) cin >> b[i];
    sort(a.begin(),a.end());
    sort(b.begin(),b. end());
    vector<ll> s(m+1);
    rep(i,m) s[i+1] = s[i] + b[i];
    ll ans =0;
    rep(i,n){
        int j = lower_bound(b.begin(),b.end(),p-a[i]) - b.begin();
        ans += p*ll(m-j);
        ans += a[i]*ll(j);
        ans+= s[j];
    }
    cout << ans << endl;
    return 0;
}