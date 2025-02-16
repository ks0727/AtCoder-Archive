#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using T = tuple<int,int,int>;
template<class S,auto op, auto e> struct segtree{
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
    S prod(int l, int r){
        l += n; r += n;
        S lb = e(), rb = e();
        while(r > l){
            if(l&1) lb = op(lb,d[l++]);
            if(r&1) rb = op(rb,d[--r]);
            l>>=1;
            r>>=1;
        }
        return op(rb,lb);
    }
    void show(){
        rep(i,n){
            cout << d[i+n] << ' ';
        }
        cout << endl;
    }
};
vector<int> comp(vector<int> a){
    vector<int> res = a;
    sort(res.begin(),res.end());
    res.erase(unique(res.begin(),res.end()),res.end());
    return res;
}
int op(int a,int b){return max(a,b);}
int e(){return 0;}
int main(){
    int n,q;
    cin >> n >> q;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<T> qs;
    rep(qi,q){
        int r,x;
        cin >> r >> x;
        qs.emplace_back(r,x,qi);
    }
    sort(qs.begin(),qs.end());
    vector<int> b = comp(a);
    int now = 0;
    segtree<int,op,e> seg(n);
    vector<int> ans(q);
    rep(qi,q){
        auto [r,x,idx] = qs[qi];
        while(now < r){
            int id = lower_bound(b.begin(),b.end(),a[now]) - b.begin();
            int mx = seg.prod(0,id);
            seg.set(id,mx+1);
            now++;
        }
        int id = upper_bound(b.begin(),b.end(),x) - b.begin();
        int ok = seg.prod(0,id);
        ans[idx] = ok;
    }
    rep(i,q) cout << ans[i] << '\n';
    return 0;
}