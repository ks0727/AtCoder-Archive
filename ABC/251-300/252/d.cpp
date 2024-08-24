#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using P = pair<int,int>;
using ll = long long;


int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    const int M = 2e5;
    rep(i,n) cin >> a[i],a[i]--;
    vector<int> cnt(M);
    rep(i,n) cnt[a[i]]++;
    vector<int> now(M);
    ll ans = 0;
    rep(i,n){
        int pre = now[a[i]];
        int lat = cnt[a[i]]-pre-1;
        ans += (ll)(i-pre)*(n-i);
        ans += (ll)(n-i-lat)*(i);
        ans -= (ll)(pre)*(n-i+1);
        ans -= (ll)(lat)*(i+1);
        now[a[i]]++;
    }
    cout << ans << endl;
    return 0;
}