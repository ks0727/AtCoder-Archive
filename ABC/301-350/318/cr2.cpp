#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main(){
    int n,d,p;
    cin >> n >> d >> p;
    vector<int> f(n);
    rep(i,n) cin >> f[i];
    sort(f.begin(),f.end());
    vector<ll> sums(n);
    ll sum = 0;
    rep(i,n){
        sum += (ll)f[i];
        sums[i] = sum;
    }
    ll ans = sums[n-1];
    for(int i=1;i <= n/d +1 ;i++){
        if(n-1-d*i < 0) ans = min(ans,(ll)p*i);
        else ans = min(ans,(ll)p*i+sums[n-1-d*i]);
    }
    ans = min(ans,(ll)(n/d+1)*p);
    cout << ans << endl;
}