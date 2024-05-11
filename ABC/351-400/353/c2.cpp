#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main(){
    int n;
    cin >> n;
    int M = 1e8;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    sort(a.begin(),a.end());
    ll ans = 0;
    rep(i,n) ans += (ll)a[i]*(n-1);
    ll cnt = 0;
    rep(i,n-1){
        int pi = lower_bound(a.begin()+i+1,a.end(),M-a[i]) - a.begin();
        pi = max(pi,i+1);
        //if(pi > n || a[i]+a[pi]<M) continue;
        cnt += (n-pi);
    }
    ans -= (ll)cnt*M;
    cout << ans << endl;
    return 0;
}