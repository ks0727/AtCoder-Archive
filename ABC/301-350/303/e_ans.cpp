#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    cin >> n;
    vector<vector<int> > to(n);
    rep(i,n-1){
        int a,b;
        cin >> a >> b;
        --a;--b;
        to[a].push_back(b);
        to[b].push_back(a);
    }
    int leaf = -1;
    rep(i,n){
        if(to[i].size() == 1) leaf = i;
    }
    vector<int> ans;
    auto dfs = [&](auto dfs, int v, int p = -1,int d=0) -> void{
        if(d % 3 == 1){
            ans.push_back(to[v].size());
        }
        for(int u : to[v]){
            if(u != p){
                dfs(dfs,u,v,d+1);
            }
        }
    };
    dfs(dfs,leaf);
    sort(ans.begin(),ans.end());
    for(int a : ans) cout << a << ' ';
    cout << endl;
    return 0;
}