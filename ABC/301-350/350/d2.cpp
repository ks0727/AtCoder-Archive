#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for(int i=0;i<(n);i++)
using P = pair<int,int>;
using ll = long long;

ll c2(int x){
    return (ll)x*(x-1)/2;
}

int main(){
    int n,m;
    cin >> n >> m;
    dsu uf(n);
    vector<P> es(m);
    rep(i,m){
        int a,b;
        cin >> a >> b;
        --a; --b;
        uf.merge(a,b);
        es[i] = P(a,b);
    }
    vector<int> vs(n);
    rep(i,n){
        vs[uf.leader(i)]++;
    }
    vector<int> e(n);
    rep(i,m){
        int a = es[i].first;
        e[uf.leader(a)]++;
    }
    ll ans = 0;
    rep(i,n){
        ans += c2(vs[i]);
        ans -= e[i];
    }
    cout << ans << endl;
}
