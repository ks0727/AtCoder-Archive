#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using ll = long long;

template<class S, auto op, auto e> struct segtree{
    int n,size;
    vector<S> node;
    segtree():segtree(0){}
    segtree(int n):n(n){
        size = 1;
        while(n > size) size *= 2;
        node.resize(2*size,e());
    }
    void update(int k){
        node[k] = op(node[2*k],node[2*k+1]);
    }
    void set(int i, S x){
        i += size;
        node[i] = x;
        while(i){
            update(i>>1);
            i >>= 1;
        }
    }
    void get(int i){
        return node[i+size];
    }
    S prod(int l,int r){
        l += size; r += size;
        S lb = e(), rb = e();
        while(l < r){
            if(l&1) lb = op(lb,node[l++]);
            if(r&1) rb = op(rb,node[--r]);
            l >>= 1;
            r >>= 1;
        }
        return op(lb,rb);
    }
};

ll op(ll a, ll b){return max(a,b);}
ll e(){return 0;}

int main(){
    int n;
    cin >> n;
    vector<ll> ws(n);
    ll sum = 0;
    rep(i,n){
        cin >> ws[i];
        sum += ws[i]*2;
    }
    vector<int> p(n);
    rep(i,n) cin >> p[i],p[i]--;
    segtree<ll,op,e> seg(n);
    //cout << seg.size << endl;
    rep(i,n){
        seg.set(p[i],seg.prod(0,p[i])+ws[p[i]]*2);
    }
    cout << sum - seg.prod(0,n) << endl;
    return 0;
}