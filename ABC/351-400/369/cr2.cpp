#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using ll = long long;

int main(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<int> d(n-1);
    rep(i,n-1) d[i] = a[i+1] - a[i];
    int r = 0;
    ll ans = n;
    for(int l=0;l<n-1;l++){
        while(r < n-1 && d[r] == d[l]){
            r++;
        }
        //cout << l << ' ' << r << endl;
        ans += r-l;
        if(r == l) r++;
    }
    cout << ans << endl;
    return 0;
}