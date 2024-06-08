#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i],a[i]--;
    vector<vector<int> > in(n);
    rep(i,n){
        in[a[i]].push_back(i);
    }
    vector<int> ans(n);
    vector<int> visit(n,-1);
    auto dfs = [&](auto dfs,int v,int depth)->void{
        visit[v] = depth;
        int u = a[v];
        if(visit[u] != -1){ //すでに訪問済みの場合
            int cycle = depth+1 - visit[u];
            queue<int> q; q.push(v);
            while(!q.empty()){
                int s = q.front(); q.pop();
                for(int t : in[s]){
                    
                }
            }
        }
    };
    return 0;
}