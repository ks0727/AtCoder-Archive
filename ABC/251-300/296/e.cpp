#include <iostream>
#include <vector>
#include <set>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    cin >> n;
    vector<vector<int> > g(n);
    vector<int> a(n);
    rep(i,n){
        cin >> a[i];
        a[i]--;
    } 
    rep(i,n){
        g[i].push_back(a[i]);
    }
    vector<bool> visited(n);
    vector<bool> finished(n);
    auto dfs = [&](auto dfs,int v)->bool{
        visited[v] = true;
        for(int u : g[v]){
            if(finished[u]) continue;
            if(visited[u] && !finished[u]) return true;
            if(dfs(dfs,u)) return true;
            visited[v] = false;
        }
        finished[v] = true;
        return false;
    };
    auto f = [&](auto f,int v,vector<int> roop,int start,vector<bool> seen)->void{
        roop.push_back(v);
        seen[v] = true;
        if(roop.size() != 1 && v == start) return;
        for(int u : g[v]){
            if(seen[u]) continue;
            f(f,u,roop,start,seen);
        }
    };
    int ans = 0;
    vector<bool> seen(n);
    rep(i,n){
        if(!seen[i]){
            if(dfs(dfs,i)){
                cout << "ok" << endl;
                vector<int> roop;
                f(f,i,roop,i,seen);
                roop.erase(unique(roop.begin(),roop.end()),roop.end());
                ans += roop.size();
            }
        }
    }
    cout << ans << endl;
    return 0;
}