#include <bits/stdc++.h>
using namespace std;
#include<atcoder/fenwicktree>
#define rep(i,n) for(int i=0;i<n;++i)
using ll = long long;
using namespace atcoder;
using P = pair<int,int>;
int main(){
    int n,m;
    cin >> n >> m;
    vector a(n,vector<int>(m));
    rep(i,n)rep(j,m) cin >> a[i][j];
    vector<P> b;
    rep(i,n)rep(j,m) b.emplace_back(a[i][j],i);
    sort(b.begin(),b.end());

    ll ans = (m+1)*m/2 * (n+1)*n/2;
    fenwick_tree<int> t(n);
    for(auto [_,x] : b){ //転倒数はfenwick treeを使う
        t.add(x,1);
        ans += t.sum(x+1,n);
    }
    cout << ans << endl;
    return 0;
}