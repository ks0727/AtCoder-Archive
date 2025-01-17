#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

template<class S,auto op,auto e> struct segtree{
    int n;
    vector<S> d;
    segtree(int n):n(n){
        d.resize(2*n,e());
    }
    void update(int k){
        d[k] = op(d[2*k],d[2*k+1]);
    }
    void set(int p,S x){
        p += n;
        d[p] = x;
        while(p){
            update(p>>1);
            p>>=1;
        }
    }
    S get(int p){
        return d[p+n];
    }
    S prod(int l,int r){
        l += n; r+=n;
        S lb = e(),rb=e();
        while(r>l){
            if(l&1) lb = op(lb,d[l++]);
            if(r&1) rb = op(rb,d[--r]);
            l>>=1;
            r>>=1;
        }
        return op(rb,lb);
    }
    void show(){
        for(int i=0;i<n;i++){
            cout << d[i+n] << ' ';
        }
        cout << endl;
    }
};

int op(int a, int b){return a+b;}
int e(){
    return 0;
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<int> b(n);
    segtree<int,op,e> seg(n+1);
    rep(i,n){
        a[i] += seg.prod(0,i+1);
        int give = min(a[i],n-i-1);
        a[i] -= give;
        seg.set(i+1,seg.get(i+1)+1);
        seg.set(i+1+give,seg.get(i+1+give)-1);
        //seg.show();
    }
    rep(i,n) cout << a[i] << ' '; cout << endl;
    return 0;
}