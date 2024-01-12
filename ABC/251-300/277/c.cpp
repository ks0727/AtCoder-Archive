#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    cin >> n;
    map<int,set<int> > mp;
    rep(i,n){
        int a,b;
        cin >> a >> b;
        mp[a].insert(b);
        mp[b].insert(a);
    }
    set<int> visited;
    int highest = 1;
    auto dfs = [&](auto dfs,int v)->void{
        visited.insert(v);
        highest = max(highest,v);
        for(int u : mp[v]){
            if(visited.count(u)) continue;
            dfs(dfs,u);
        }
    };
    dfs(dfs,1);
    cout << highest << endl;
    return 0;
}