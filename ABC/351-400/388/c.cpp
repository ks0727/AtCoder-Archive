#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    int n;
    cin >> n;
    vector<long long> a(n);
    rep(i,n) cin >> a[i];
    long long ans = 0;
    rep(i,n){
        long long now = a.end()-lower_bound(a.begin(),a.end(),a[i]*2);
        ans += now;
    }
    cout << ans << endl;
    return 0;
}