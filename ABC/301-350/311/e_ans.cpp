#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main(){
    int h,w,n;
    cin >> h >> w >> n;
    vector d(h+1,vector<int>(w+1));
    rep(i,n){
        int a,b;
        cin >> a >> b;
        d[a][b] = 1;
    }
    rep(i,h+1)rep(j,w) d[i][j+1] += d[i][j];
    rep(i,h)rep(j,w+1) d[i+1][j] += d[i][j];

    auto sum = [&](int li, int lj, int ri, int rj){
        int res = d[ri][rj];
        res -= d[li][rj];
        res -= d[ri][lj];
        res += d[li][lj];
        return res;
    };

    ll ans = 0;
    for(int i=1;i<=h;i++)for(int j=1;j<=w;j++){
        int ac = 0, wa = min(i,j)+1;
        while(ac+1 < wa){
            int wj = (ac+wa)/2;
            if(sum(i-wj,j-wj,i,j) == 0) ac = wj;
            else wa = wj;
        }
        ans += ac;
    }
    return 0;
}