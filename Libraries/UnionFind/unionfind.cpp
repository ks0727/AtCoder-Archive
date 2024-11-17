#include <iostream>
using namespace std;

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
