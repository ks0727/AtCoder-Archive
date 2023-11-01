#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    cin >> n;
    vector<vector<int> > to(n);
    rep(i,n){
        int c;
        cin >> c;
        rep(j,c){
            int p;
            cin >> p;
            to[i].push_back(p-1);
        }
    }
    vector<bool> visited(n);
    vector<int> ans;
    auto dfs = [&](auto dfs, int v) -> void{
        visited[v] = true;
        for(int u : to[v]){
            if(visited[u]) continue;
            dfs(dfs,u);
        }
        ans.push_back(v);
    };
    dfs(dfs,0);
    ans.pop_back();
    for(int v : ans) cout << v+1 << ' ';
    cout << endl;
    }