#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    cin >> n;
    vector<pair<string,int> > s(n);
    rep(i,n){
        cin >> s[i].first;
        s[i].second = i;
    } 
    vector<int> ans(n);
    auto dfs = [&](auto dfs,vector<pair<string,int> > g, int depth)->void{
        vector<vector<pair<string,int> >> d(26);
        rep(i,int(g.size())){
            d[g[i].first[depth]-'a'].push_back(g[i]);
        }
        rep(i,26){
            if(int(d[i].size()) == 0) continue;
            if(int(d[i].size()) == 1){
                ans[d[i][0].second] = depth;
            }else{
                vector<pair<string,int> > g2;
                rep(j,int(d[i].size())){
                    if(int(d[i][j].first.size()) == depth+1){
                        ans[d[i][j].second] = depth+1;
                    }else{
                        g2.push_back(d[i][j]);
                    }
                }
                dfs(dfs,g2,depth+1);
            }
        }
    };
    dfs(dfs,s,0);
    rep(i,n) cout << ans[i] << endl;
    return 0;
}