#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using ll = long long;

int main(){
    int n; ll k;
    cin >> n >> k;
    vector<int> p(n);
    rep(i,n) cin >> p[i],p[i]--;
    vector<vector<int> > to(61,vector<int>(n));
    rep(i,n) to[0][i] = p[i];
    for(int s=0;s<60;s++){
        rep(i,n) to[s+1][i] = to[s][to[s][i]];
    }
    vector<int> ans(n);
    rep(i,n){
        int pos = p[i];
        rep(s,61){
            if(k>>s&1){
                pos = p[to[s][pos]];
            }
        }
        ans[i] = pos+1;
    }
    rep(i,n) cout << ans[i] << ' '; cout << endl;
    return 0;
}