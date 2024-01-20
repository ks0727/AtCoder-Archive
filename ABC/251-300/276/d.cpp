#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main(){
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    bool exist = false;
    
    rep(i,n){
        if(a[i]%2 != 0 && a[i] %3 != 0 && a[i] != 1){
            exist = true;
            break;
        }
    }
    ll g = a[0];
    rep(i,n){
        ll now = gcd(a[i],g);
        g = now;
    }
    ll ans = 0;
    if(exist && g == 1){
        cout << -1 << endl;
    }else{
        rep(i,n){
            a[i] /= g;
            while(a[i]%2 == 0){
                a[i] /= 2;
                ans++;
            }
            while(a[i]%3 == 0){
                a[i] /= 3;
                ans++;
            }
            if(a[i] != 1){
                cout << -1 << endl;
                return 0;
            }
        }
        cout << ans << endl;
    }
    return 0;
}   