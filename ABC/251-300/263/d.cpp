#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

const ll INF = 1e18;
ll op(ll a, ll b){return min(a,b);}
ll e(){return INF;}

int main(){
    int n,l,r;
    cin >> n >> l >> r;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    ll sum = 0;
    rep(i,n) sum += a[i];
    vector<ll> dx(n),dy(n),sdy(n+1);
    segtree<ll,op,e> seg(n+1);
    rep(i,n){
        dx[i] = l - a[i];
        dy[n-i-1] = r - a[n-i-1];
    }
    reverse(dy.begin(),dy.end());
    ll now = 0;
    seg.set(0,0);
    rep(i,n){
        seg.set(i+1,now+dx[i]); 
        sdy[i+1] = sdy[i] + dy[i];
        now += dx[i];
    } 
    reverse(sdy.begin(),sdy.end());
    ll ans = INF;
    for(int i=n;i>=1;i--){
        ans = min(ans,sdy[i] + seg.prod(0,i+1));
    }
    ans = min(ans,sdy[0]);
    cout << sum + ans << endl;
    return 0;
}