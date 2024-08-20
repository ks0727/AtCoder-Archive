#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using ll = long long;

int main(){
    int n; ll k;
    cin >> n >> k;
    vector<int> x(n),a(n);
    rep(i,n) cin >> x[i],x[i]--;
    rep(i,n) cin >> a[i];
    vector d(62,vector<int>(n));
    rep(i,n) d[0][i] = x[i];

    rep(i,61){
        rep(j,n) d[i+1][j] = d[i][d[i][j]];
    }
    rep(i,61){
        if((k>>i) & 1){
            vector<int> b = a;
            rep(j,n) b[j] = a[d[i][j]];
            a = b;
        }
    }
    rep(i,n) cout << a[i] << ' '; cout << endl;
    return 0;
}