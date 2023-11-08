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
    sort(b.begin(),b.end());
    vector<ll> s(m);
    s[0] = b[0];
    for(int i=0;i<(m-1);i++){
        s[i+1] = s[i] + (ll)b[i+1];
    }
    ll ans = 0;
    rep(i,n){
        int k = lower_bound(b.begin(),b.end(),p-a[i]) - b.begin();
        if(k == 0) ans += (ll)p * m;
        else{
            ans += (ll)p*(m-k);
            ans += (ll)a[i]*k + s[k-1];
        }
    }
    cout << ans << endl;
    return 0;
}