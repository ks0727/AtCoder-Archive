#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;
int main(){
    int n,m;
    cin >> n >> m;
    vector<ll> a(m);
    rep(i,m) cin >> a[i];
    vector<ll> s(m);
    rep(i,n){
        vector<ll> x(m);
        rep(j,m) cin >> x[j];
        rep(j,m) s[j] += x[j];
    }
    bool ans = true;
    rep(i,m) if(s[i] < a[i]) ans = false;
    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}