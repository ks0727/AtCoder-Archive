#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using ll = long long;
int main(){
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<int> b(n);
    rep(i,n){
        int cnt = 0;
        while(a[i]%2 == 0) {
            a[i]/=2;
            cnt++;
        }
        b[i] = cnt;
    }
    ll ans = 0;
    rep(i,n) ans += a[i];
    
    return 0;
}