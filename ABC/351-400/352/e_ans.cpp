#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;
using E = tuple<int,int,int>;

int main(){
    int n,m;
    cin >> n >> m;
    vector<E> es;
    rep(i,m){
        int k,c;
        cin >> k >> c;
        vector<int> a(k);
        rep(j,k) cin >> a[j], a[j]--;
        rep(j,k-1){
            es.emplace_back(c,a[j],a[j+1]);
        }
    }
    sort(es.begin(),es.end());
    dsu uf(n);
    ll ans = 0;
    for(auto [c,a,b] : es){
        if(uf.same(a,b)) continue;
        uf.merge(a,b);
        ans += c;
    }
    if(uf.size(0) != n) ans = -1;
    cout << ans << endl;
    return 0;
}