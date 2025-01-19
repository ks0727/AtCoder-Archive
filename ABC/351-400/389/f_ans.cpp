#include <bits/stdc++.h>
using namespace std;
#include <atcoder/lazysegtree>
using namespace atcoder;
#define rep(i,n) for(int i=0;i<n;++i)

int op(int a,int b){return max(a,b);}
int e(){return 0;}
int mapping(int f,int x){return x+f;}
int composition(int f, int g){return g+f;}
int id(){return 0;}

int main(){
    int n;
    cin >> n;
    const int M = 5e5+5;
    lazy_segtree<int,op,e,int,mapping,composition,id> t(M);

    auto lwb = [&](int x){
        auto f = [&](int a){return a<x;};
        return t.max_right(0,f);
    };
    rep(i,n){
        int l,r;
        cin >> l >> r;
        r++;
        int lb = lwb(l),rb = lwb(r);
        t.apply(lb,rb,1);
    }
    int Q;
    cin >> Q;
    while(Q--){
        int x;
        cin >> x;
        int ans = t.get(x);
        cout << ans << endl;
    }
    return 0;
}