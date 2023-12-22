#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    cin >> n;
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    vector<int> idxs;
    rep(i,n) idxs.push_back(i);
    const int INF = 1e9;
    vector<int> ans(n,INF);
    auto dfs = [&](auto dfs,vector<int> idxs, int now)->void{
        vector<vector<int> > d(26);
        rep(i,idxs.size()){
            d[s[idxs[i]][now]-'a'].push_back(idxs[i]);
        }
        rep(i,26){
            if(d[i].size() == 0) continue;
            if(d[i].size() == 1){
                if(ans[d[i][0]] == INF) ans[d[i][0]] = now;
                continue;
            }
            vector<int> d2;
            rep(j,d[i].size()){
                if(s[d[i][j]].size() == now+1){
                    if(ans[d[i][j]] == INF) ans[d[i][j]] = now+1;
                }else{
                    d2.push_back(d[i][j]);
                }
            }
            dfs(dfs,d2,now+1);
        }
    };
    dfs(dfs,idxs,0);
    rep(i,n) cout << ans[i] << '\n';
    return 0;
}