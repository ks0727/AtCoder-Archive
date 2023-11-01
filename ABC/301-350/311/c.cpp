#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
vector<bool> seen;
auto dfs(auto ＆dfs, int v){
    seen[v] = true;
    for(auto u : dfs[v]){
        if(seen[u]) continue;
        dfs(dfs,u);
    }
}
int main(){

}
