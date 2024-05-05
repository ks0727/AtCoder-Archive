#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

struct Edge{
    ll cost; int a,b;
    Edge(ll cost, int a,int b):cost(cost),a(a),b(b){}
    bool operator<(const Edge& o) const {
        return cost < o.cost;
    }
};

int main(){
    int n,m;
    cin >> n >> m;
    vector<Edge> es;
    dsu uf1(n);
    rep(mi,m){
        int k; ll c;
        cin >> k >> c;
        vector<int> A(k);
        rep(i,k){
            cin >> A[i];
            A[i]--;
        } 
        rep(j,k){
            for(int l=j+1;l<k;l++){
                if(!uf1.same(A[j],A[l])) uf1.merge(A[j],A[l]);
                es.push_back(Edge(c,A[j],A[l]));
            }
        }
    }
    if(uf1.size(0) != n){
        cout << -1 << endl;
        return 0;
    }
    sort(es.begin(),es.end());
    dsu uf(n);
    ll ans = 0;
    rep(ei,es.size()){
        Edge e = es[ei];
        if(uf.same(e.a,e.b)) continue;
        ans += e.cost;
        uf.merge(e.a,e.b);
    }
    cout << ans << endl;
    return 0;
}