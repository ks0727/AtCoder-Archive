#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using P = pair<int,int>;
using ll = long long;
int main(){
    int n,m;
    cin >> n >> m;
    vector<P> ps(n);
    rep(i,n) cin >> ps[i].second >> ps[i].first;
    sort(ps.begin(),ps.end());
    int now = 0;
    int l = 1;
    int r = 1;
    ll ans = 0;
    for(int l=1;l<=m;l++){
        if(l == r){
            if(now == n) r = m;
            else{
                now++;
                r = max(r,ps[now].first-1);
            }
        }
        if(l > r) continue;
        ans += r-l;
    }
    cout << ans << endl;
    return 0;
}
