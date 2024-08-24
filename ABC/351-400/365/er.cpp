#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
using ll = long long;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<int> s(n+1);
    rep(i,n) s[i+1] = s[i]^a[i];
    rep(i,n+1) cout << s[i] << " "; cout << endl;
    ll ans = 0;

    rep(k,30){
        int zero = 1;
        rep(i,n){
            if((s[i+1]>>k)&1){
                if((s[i] >> k) & 1) ans += zero;
                else ans += zero-1;
            }else{
                zero++;
                if((s[i]>>k) & 1) ans += i-zero;
                else ans += (i+1) - zero;
            }
        }
    }
    cout << ans << endl;
}