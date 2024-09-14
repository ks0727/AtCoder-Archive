#include <bits/stdc++.h>
using namespace std;
#include <atcoder/segtree>
using namespace atcoder;
#define rep(i,n) for(int i=0;i<n;++i)
using ll = long long;

ll op(ll a, ll b){return max(a,b);}
ll e(){return 0;}

int main(){
    int n;
    cin >> n;
    vector<ll> ws(n);
    vector<int> p(n);
    ll sum = 0;
    rep(i,n){
        cin >> ws[i];
        sum += ws[i]*2;
    }
    rep(i,n) cin >> p[i],p[i]--;
    segtree<ll,op,e> seg(n);
    rep(i,n){
        seg.set(p[i],seg.prod(0,p[i])+ws[p[i]]*2);
    }
    cout << sum - seg.all_prod() << endl;
    return 0;
}