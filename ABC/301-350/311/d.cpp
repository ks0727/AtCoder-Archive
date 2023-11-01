#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)


int main(){
    int n,m;
    cin >> n >> m;
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    vector<vector<bool> > seen;
    auto dfs = [&](auto dfs, auto pos) -> void{
        seen[pos.first][pos.second] = true;
        for(auto u : s[pos.first][pos.second]){
            if(seen[u.first][u.second]) continue;
            dfs(dfs,u);
        }
    };
    
}