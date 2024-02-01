#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using P = pair<int,int>;

int main(){
    int n,m;
    cin >> n >> m;
    const int INF = 1001001001;
    vector<P> dij;
    for(int di =-n;di<n;di++){
        for(int dj = -n;dj<n;dj++){
            if(di*di+dj*dj == m){
                dij.emplace_back(di,dj);
            }
        }
    }
    vector<vector<int> > g(n,vector<int>(n,INF));
    queue<P> q;
    int depth = 0;
    q.push(P(0,0));
    g[0][0] = 0;
    while(!q.empty()){
        auto [i,j] = q.front(); q.pop();
        rep(k,dij.size()){
            int ni = i+dij[k].first; int nj = j+dij[k].second;
            if(ni < 0 || nj < 0 || ni >= n || nj >= n) continue;
            if(g[ni][nj] != INF) continue;
            q.push(P(ni,nj));
            g[ni][nj] = g[i][j] + 1;
        }
    }
    rep(i,n){
        rep(j,n){
            if(g[i][j] == INF) cout << -1 << ' ';
            else cout << g[i][j] << ' ';
        }
        cout << endl;
    }
}