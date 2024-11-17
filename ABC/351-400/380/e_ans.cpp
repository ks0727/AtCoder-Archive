#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

struct UnionFind{
    int n;
    vector<int> par,rank;
    UnionFind(int n):n(n),par(n),rank(n,1){
        for(int i=0;i<n;i++) par[i] = i;
    }
    int root(int x){
        if(x == par[x]) return x;
        return par[x] = root(par[x]);
    }
    void merge(int a,int b){
        int na = root(a); int nb = root(b);
        if(na == nb) return;
        if(rank[na] > rank[nb]) swap(na,nb);
        rank[nb] += rank[na];
        par[na] = nb;
    }
    int size(int a){
        return rank[root(a)];
    }
    bool same(int a,int b){
        return root(a) == root(b);
    }
};

int main(){
    int n,q;
    cin >> n >> q;
    vector<int> cnt(n+2,1);
    UnionFind uf(n+2);
    vector<int> l(n+2),r(n+2),col(n+2);
    rep(i,n+2) l[i] = r[i] = col[i] = i;
    rep(qi,q){
        int type;
        cin >> type;
        if(type == 1){
            int x,c;
            cin >> x >> c;
            x = uf.root(x);
            int sz = uf.size(x);
            cnt[col[x]] -= sz;
            col[x] = c;
            cnt[col[x]] += sz;
            {//左とmerge
                int li = uf.root(l[x]-1);
                if(col[li] == c) {
                    int nl = l[li];
                    int nr = r[x];
                    uf.merge(li,x);
                    x = uf.root(x);
                    l[x] = nl;
                    r[x] = nr;
                    col[x] = c;
                }
            }
            {//右とmerge
                int ri = uf.root(r[x]+1);
                if(col[ri] == c){
                    int nl = l[x];
                    int nr = r[ri];
                    uf.merge(ri,x);
                    x = uf.root(x);
                    l[x] = nl;
                    r[x] = nr;
                    col[x] = c;
                }
            }
        }else{
            int c;
            cin >> c;
            cout << cnt[c]<< endl;
        }
    }
    return 0;
}