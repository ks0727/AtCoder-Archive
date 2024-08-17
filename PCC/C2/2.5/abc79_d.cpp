#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    int h,w;
    cin >> h >> w;
    vector c(10,vector<int>(10));
    rep(i,10)rep(j,10) cin >> c[i][j];
    const int INF = 1001001001;
    rep(k,10)rep(i,10)rep(j,10) c[i][j] = min(c[i][j],c[i][k]+c[k][j]);
    vector a(h,vector<int>(w));
    rep(i,h)rep(j,w) cin >> a[i][j];
    vector<int> cnt(10);
    rep(i,h){
        rep(j,w){
            if(a[i][j] == -1) continue;
            cnt[a[i][j]]++;
        }
    }
    int ans = 0;
    rep(i,10){
        ans += cnt[i]*c[i][1];
    }
    cout << ans << endl;
    return 0;
}