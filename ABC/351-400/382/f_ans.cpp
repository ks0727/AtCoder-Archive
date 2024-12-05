#include <bits/stdc++.h>
using namespace std;
#include<atcoder/all>
using namespace atcoder;
#define rep(i,n) for(int i=0;i<n;++i)

const int INF = 1001001001;
int op(int a,int b){return min(a,b);}
int e(){return INF;}
int mapping(int f,int x){ min(x,f);}
int composition(int f,int g){return min(f,g);}
int id(){return INF;}

int main(){
    int h,w,n;
    cin >> h >> w >> n;
    vector<tuple<int,int,int,int> > bars; 
    rep(i,n){
        int r,c,l;
        cin >> r >> c >> l;
        c--;
        bars.emplace_back(r,c,c+l,i);
    }
    sort(bars.rbegin(),bars.rend());
    lazy_segtree<int,op,e,int,mapping,composition,id> t(vector<int>(w,h));
    vector<int> ans(n);
    for(auto [_,l,r,bi] : bars){
        int x = t.prod(l,r);
        ans[bi] = x;
        t.apply(l,r,x-1);
    }
    rep(i,n) cout << ans[i] << endl;
    return 0;
}