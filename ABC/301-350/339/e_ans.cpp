#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for(int i=0;i<(n);i++)

int op(int a,int b){
    return max(a,b);
}
int e(){
    return 0;
}

int main(){
    int n,d;
    cin >> n >> d;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    const int M = 500005;
    segtree<int,op,e> dp(M);
    
    rep(i,n){
        int l = a[i]-d; int r= a[i]+d;
        l = max(0,l);
        r = min(r,M);
        int now = dp.prod(l,r+1) + 1; //引数は半開区間
        dp.set(a[i],now);
    }
    int ans = dp.prod(0,M);
    cout << ans << endl;
    return 0;
}