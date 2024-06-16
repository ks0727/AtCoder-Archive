#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n,m;
    cin >> n >> m;
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    vector<int> use;
    int ans = 1000;

    auto dfs = [&](auto dfs, int v)->void{
        if(v == n){
            vector<bool> sell(m);
            for(int x : use){
                rep(i,s[x].size()){
                    if(s[x][i] == 'o') sell[i] = true;
                }
            }
            rep(i,m){
                if(!sell[i]) return;
                if(i == m-1) ans = min(ans,int(use.size()));
            }
            return;
        }
        dfs(dfs,v+1); //使わない
        use.push_back(v);
        dfs(dfs,v+1); //使う
        use.pop_back();
    };
    
    dfs(dfs,0);
    cout << ans << endl;
    return 0;
}