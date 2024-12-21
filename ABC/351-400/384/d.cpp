#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using ll = long long;
int main(){
    int n; ll s;
    cin >> n >> s;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    ll sum = 0;
    rep(i,n) sum += a[i];
    s %= sum;
    vector<ll> b(2*n);
    rep(i,n){
        b[i] = a[i];
        b[i+n] = a[i];
    }
    int r = 0;
    ll now = 0;
    rep(l,2*n){
        while(r < 2*n && now < s){
            now += b[r];
            r++;
        }
        if(now == s){
            cout << "Yes" << endl;
            return 0;
        }
        if(r == l) r++;
        else now -= b[l];
    }
    cout << "No" << endl;
    return 0;
}