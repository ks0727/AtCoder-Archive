#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for(int i=0;i<n;i++)
using ll = long long;
using P = tuple<int,int,ll,int>;

struct Edge{
    int a,b; ll cost;
        bool operator<(const Edge& o)const{
        return cost < o.cost;
    }
    Edge(int a, int b, ll cost):a(a),b(b),cost(cost){}
};

int main(){
    int n,q;
    cin >> n >> q;
    vector<Edge> es;
    set<P> range;
    dsu uf(n+q);
    rep(i,q){
        int l,r; ll c;
        cin >> l >> r >> c;
        l--; r--;
        range.emplace(l,r,c,i);
    }
    int now = 0;
    int pl=0,pr = 0;
    ll pc = 0,pi = 0;
    stack<P> st;
    int id = 0;
    for(auto [l,r,c,idx] : range){
        es.emplace_back(l,id+n,c);
        if(l > pr){
            st.emplace(pl,pr,pc,pi);
            pl= l; pr = r; pc = c; pi = idx;
        }else if (l >= pl && r >= pr) pr = r;
        else if(l >= pl && r< pr) continue;
        id++;
    }
    auto[tl,tr,tc,ti] = st.top();
    if(tl != pl || tr != pr) st.emplace(pl,pr,pi,pc);
    set<P> all;
    while(!st.empty()){
        all.emplace(st.top()); st.pop();
    }
    all.erase(all.begin());
    for ()
    sort(es.begin(),es.end());
    ll ans = 0;
    rep(i,es.size()){
        auto [a,b,cost] = es[i];
        if(!uf.same(a,b)){
            ans += cost;
            uf.merge(a,b);
        }
    }
    if(uf.size(0) != n+q) ans = -1;
    cout << ans << endl;
    return 0;
}