#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for(int i=0;i<(n);i++)
using P = pair<int,int>;

int main(){
    int n,m,e;
    cin >> n >> m >> e;
    vector<P> es;
    rep(i,e){
        int u,v;
        cin >> u >> v;
        u--; v--;
        es.emplace_back(u,v);
    }
    int q;
    cin >> q;
    vector<int> qs(q);
    vector<bool> cut(e);
    rep(qi,q){
        int x;
        cin >> x;
        x--;
        qs[qi] = x;
        cut[x] = true;
    }
    dsu uf(n+m);
    vector<bool> on(n+m); //それぞれの地点は発電所と繋がっているか？
    rep(i,m) on[n+i] = true; // 発電所自身はもちろん発電所と繋がっている
    int now = m;
    auto add = [&](int v,int coef = 1){
        v = uf.leader(v);
        if(on[v]) now += uf.size(v)*coef;  //nowにvの連結成分の個数を足す
    };
    auto merge = [&](int a,int b){ //aとbが異なる連結成分に属しているとき, 
        if(uf.same(a,b)) return;
        add(a,-1); //aを含む連結成分のサイズを引く
        add(b,-1); //bを含む連結成分のサイズを引く
        bool ison = on[uf.leader(a)] | on[uf.leader(b)]; //aまたはbの代表元が発電所と繋がっているか？
        uf.merge(a,b);
        on[uf.leader(a)] = ison; //aまたはbの代表元が発電所と繋がっているのならば、aの代表も発電所と繋がっている
        add(a); //aを含む連結成分のサイズをたす
    };
    rep(i,e){
        if(!cut[i]){
            auto [a,b] = es[i];
            merge(a,b);
        }
    }
    vector<int> ans(q);
    for(int qi = q-1;qi>=0;qi--){
        ans[qi] = now-m;
        auto [a,b] = es[qs[qi]];
        merge(a,b);
    }
    rep(qi,q) cout << ans[qi] << '\n';
    return 0;
}
