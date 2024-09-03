#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using ll = long long;

int main(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];    
    vector<int> d(n-1);
    rep(i,n-1) d[i] = a[i+1]-a[i];
    ll ans = n;
    rep(l,n-1){
        int r = l+1;
        while (r < n-1 && d[l]==d[r]) r++;
        ll len = r-l;
        ans += len*(len+1)/2;
        l = r;
    }
    cout << ans << endl;
    return 0;
}