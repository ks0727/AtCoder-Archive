#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using P = pair<int,int>;

int main(){
    int n;
    cin >> n;
    vector<vector<P> > pe(n);
    rep(i,n){
        int m; cin >> m;
        rep(j,m){
            int p,e;
            cin >> p >> e;
            pe[i].emplace_back(p,e);
        }
    }
    map<int,int> mx;
    rep(i,n){
        for(auto [p,e] : pe[i]){
            mx[p] = max(mx[p],e);
        }
    }
    map<int,int> cnt;
        rep(i,n){
        for(auto [p,e] : pe[i]){
            if(mx[p] == e) cnt[p]++;
        }
    }
    int ans = 0;
    rep(i,n){
        bool ok = false;
        for(auto [p,e] : pe[i]){
            if(mx[p] == e && cnt[p] == 1){ //maxでかつ単独であれば
                ok = true;
            }
        }
        if(ok) ans++;
    }
    if(ans < n) ans++;
    cout << ans << endl;
    return 0;
}