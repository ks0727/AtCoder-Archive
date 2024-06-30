#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main(){
    int n;
    cin >> n;
    vector<ll> a(n),w(n);
    rep(i,n) cin >> a[i],a[i]--;
    rep(i,n) cin >> w[i];
    vector<vector<ll> > box(n);
    rep(i,n) box[a[i]].push_back(w[i]);
    rep(i,n) sort(box[i].begin(),box[i].end());
    ll ans = 0;
    rep(i,n){
        if(box[i].size() >= 2){
            rep(j,box[i].size()-1){
                ans += (ll)box[i][j];
            }
        }
    }
    cout << ans << endl;
    return 0;
}