#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using P = pair<int,int>;
using ll = long long;

int main(){
    int h,w,k;
    cin >> h >> w >> k;
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    const int di[] = {1,0,-1,0};
    const int dj[] = {0,1,0,-1};
    ll ans = 0;
    rep(i,h){
        rep(j,w){
            if(s[i][j] == '#') continue;
            vector<vector<bool> > seen(h,vector<bool>(w));
            auto dfs = [&](auto dfs,P p,int d=0)->ll{
                if(d==k) return 1;
                ll res = 0;
                auto [i,j] = p;
                seen[i][j] = true;
                    rep(v,4){
                        int ni = i+di[v];
                        int nj = j+dj[v];
                        if(ni < 0 || nj < 0 || ni >= h || nj >= w) continue;
                        if(s[ni][nj] == '#') continue;
                        if(seen[ni][nj]) continue;
                        res += dfs(dfs,P(ni,nj),d+1);
                        seen[ni][nj] = false;
                    }
                return res;
            };
            ans += dfs(dfs,P(i,j),0);
        }
    }
    cout << ans << endl;
    return 0;
}