#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    string t;
    cin >> t;
    int n;
    cin >> n;
    vector<vector<string> > ss(n);
    rep(i,n){
        int a;
        cin >> a;
        rep(j,a){
            string ns;
            cin >> ns;
            ss[i].push_back(ns);
        }
    }
    const int INF = 1001001001;
    int ans = INF;
    auto dfs = [&](auto dfs,string now,int c,int idx)->void{
        if(now != t.substr(0,now.size())) return;
        if(now == t){
            ans = min(ans,c);
            return;
        }
        if(idx == n) return;
        dfs(dfs,now,c,idx+1); //何も使わない時の処理
        for(string ns : ss[idx]){
            dfs(dfs,now+ns,c+1,idx+1); //使う時の処理
        }
    };
    dfs(dfs,"",0,0);
    if(ans != INF) cout << ans << endl;
    else cout << -1 << endl;
    return 0;
}