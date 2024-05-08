#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int> > g(n);
    rep(i,m){
        int a,b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int k; cin >> k;
    vector<int> color(n,-1);
    rep(i,k){
        int p,d; cin >> p >> d;
        p--;
        vector<bool> seen(n);
        auto dfs = [&](auto dfs, int v, int depth,int target_d)->bool{
            if(depth == target_d){
                color[v] = 1;
                return true;
            }
            if(depth < d && color[v] == 1) return false;
            seen[v] = true;
            for(int u : g[v]){
                if(seen[u]) continue;
                if(dfs(dfs,u,depth+1,target_d)) return true;
            }
            return false;
        };
        if(!dfs(dfs,p,0,d)){
            cout << "No" << endl;
            return 0;
        }
        rep(i,n) cout << color[i] << ' '; cout << endl;
    }
    cout << "Yes" << endl;
    string ans = "";
    rep(i,n){
        if(color[i] == 1) ans+='1';
        else ans += '0';
    }
    cout << ans << endl;
}