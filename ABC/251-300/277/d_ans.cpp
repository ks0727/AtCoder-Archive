#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    sort(a.begin(),a.end());
    dsu uf(n);
    rep(i,n){
        int j = (i+1)%n;
        if(a[i] == a[j] || (a[i]+1)%m == a[j]){
            uf.merge(i,j);
        }
    }
    vector<ll> s(n);
    rep(i,n) s[uf.leader(i)] += a[i];
    ll mx = 0, tot = 0;
    rep(i,n) mx = max(mx,s[i]);
    rep(i,n) tot += a[i];
    cout << tot - mx << endl;
    return 0;
}