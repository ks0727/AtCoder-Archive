#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for(int i=0;i<(n);i++)
using P = pair<int,int>;

int main(){
    int n,m;
    cin >> n >> m;
    dsu uf(n);
    rep(i,m){
        int u,v;
        cin >> u >> v;
        u--; v--;
        uf.merge(u,v);
    }
    int k;
    cin >> k;
    set<P> st;
    rep(i,k){
        int x,y;
        cin >> x >> y;
        x--; y--;
        int xu = uf.leader(x);
        int yu = uf.leader(y);
        if(xu > yu) swap(xu,yu);
        st.insert(P(xu,yu));
    }
    int Q;
    cin >> Q;
    rep(qi,Q){
        int p,q;
        cin >> p >> q;
        p--; q--;
        int pu = uf.leader(p);
        int qu = uf.leader(q);
        if(pu > qu) swap(pu,qu);
        if(st.count(P(pu,qu))) cout << "No" << endl;
        else cout << "Yes" << endl;
    }
    return 0;
}