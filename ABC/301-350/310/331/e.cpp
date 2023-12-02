#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;
using P = pair<ll,ll>;
int main(){
    int n,m,l;
    cin >> n >> m >> l;
    vector<P> a(n);
    vector<P> b(m);
    set<P> p;
    rep(i,n) cin >> a[i].first;
    rep(i,m) cin >> b[i].first;
    rep(i,l){
        int c,d;
        cin >> c >> d;
        c--; d--;
        p.insert(P(c,d));
    }
    rep(i,n) a[i].second = i;
    rep(i,m) b[i].second = i;
    sort(a.rbegin(),a.rend());
    sort(b.begin(),b.end());
    ll ans = -1;
    int bindex = 0;
    rep(i,n){
        ll now = 0;
        for(int j = m-1;j>=bindex;j--){
            if(p.count(P(a[i].second,b[j].second))) continue;
            now = a[i].first + b[j].first;
            bindex = j;
            break;
        }
        ans = max(now,ans);
    }
    cout << ans << endl;
    return 0;
}