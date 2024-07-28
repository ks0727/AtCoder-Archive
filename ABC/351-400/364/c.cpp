#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
using ll = long long;
int main(){
    ll n,x,y;
    cin >> n >> x >> y;
    vector<ll> a(n),b(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    sort(a.rbegin(),a.rend());
    sort(b.rbegin(),b.rend());
    int ans = n;
    ll anow = 0;
    rep(i,n){
        anow += a[i];
        if(anow > x){
            ans = i+1;
            break;
        }
    }
    ll bnow = 0;
    rep(i,n){
        bnow += b[i];
        if(bnow > y){
            ans = min(ans,i+1);
            break;
        }
    }
    cout << ans << endl;
    return 0;
}