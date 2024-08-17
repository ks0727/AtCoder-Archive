#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
const int di[] = {1,0};
const int dj[] = {0,1};
using ll = long long;

struct UnionFind{
    int n;
    vector<int> par,rank;
    UnionFind(int n):n(n),par(n,-1),rank(n,0){
        rep(i,n) par[i] = i;
    }
    int root(int x){
        if(par[x] == x) return x;
        return par[x] = root(par[x]);
    }
    void merge(int a, int b){
        int la = root(a);
        int lb = root(b);
        if(la == lb) return;
        if(rank[la] < rank[lb]){
            par[la] = lb;
            rank[lb] += rank[la];
        }else if(rank[la] > rank[lb]){
            par[lb] = la;
            rank[la] += rank[lb];
        }else{
            par[la] = lb;
            rank[lb]+=rank[la];
        }
    }
    bool same(int a,int b){
        return root(a) == root(b);
    }
};

struct Edge{
    int a,b; ll cost;
    Edge(ll cost,int a ,int b):a(a),b(b),cost(cost){}
};

bool cmp(const struct Edge& a, const struct Edge& b){
    return a.cost > b.cost;
}

int toid(int i, int j, int w){
    return i*w+j;
}
pair<int,int> top(int id,int w){
    return make_pair(id/w,id%w);
}
int main(){
    int h,w;
    cin >> h >> w;
    int sx,sy;
    cin >> sx >> sy;
    int gx,gy;
    cin >> gx >> gy;
    sx--; sy--; gx--;gy--;
    vector p(h,vector<ll>(w));
    ll sum = 0;
    rep(i,h)rep(j,w) cin >> p[i][j],sum+=p[i][j];

    vector<Edge> es;
    rep(i,h){
        rep(j,w){
            rep(d,2){
                int ni = i + di[d]; int nj = j + dj[d];
                if(ni < 0 || nj < 0 || ni >= h || nj >= w) continue;
                es.emplace_back((ll)p[i][j]*p[ni][nj],toid(i,j,w),toid(ni,nj,w));
            }
        }
    }
    stable_sort(es.begin(),es.end(),cmp);
    vector<bool> seen(h*w);
    UnionFind uf(h*w);
    ll ans  = 0;
    for(auto e : es){
        if(!uf.same(e.a,e.b)){
            ans += e.cost;
            uf.merge(e.a,e.b);
        }
    }
    cout << ans+sum << endl;
    return 0;
}