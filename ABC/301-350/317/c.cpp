#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int> > G(m);
    map<pair<int,int>,int> distance;
    rep(i,m){
        int a,b,c;
        cin >> a >> b >> c;
        G[a-1].push_back(b-1);
        G[b-1].push_back(a-1);
        distance[make_pair(a-1,b-1)] = c;
        distance[make_pair(b-1,a-1)] = c;
    }
    int current = 0;
    int mx = 0;
    vector<bool> seen(n);

    auto dfs = [&](auto dfs, int v) -> void{
        seen[v] = true;
        for(auto next_v : G[v]){
            if(seen[next_v]){
                continue;
            }
            if(distance.count(make_pair(v,next_v))){
                current += distance[make_pair(v,next_v)];
                cout << v+1 << ' ' << next_v+1 << endl;
                cout << distance[make_pair(v,next_v)] << ' ' << current << endl;
            }
            mx = max(current,mx);
            dfs(dfs,next_v);
            current = 0;
        }
    };
    rep(i,n){
        rep(j,n) seen[j] = false;
        dfs(dfs,i);
    }
    cout << mx << endl;
    rep(i,m)rep(j,G[i].size()){
        cout << G[i][j];
        if(j==G[i].size()-1) cout << endl;
    } 
}