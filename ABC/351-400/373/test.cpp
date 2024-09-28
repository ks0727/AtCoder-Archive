#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using ll = long long;
int main(){
    int n,m;
    cin >> n >> m;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    rep(i,m){
        int u,v; ll w;
        cin >> u >> v >> w;
        u--; v--;
        if(a[v]-a[u] != w){
            cout << u <<' '  << v << endl;
            cout << a[v] - a[u] << endl;
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}