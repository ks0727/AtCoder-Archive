#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using P = pair<int,int>;

int main(){
    int n,m;
    cin >> n >> m;
    const int INF = 1001001001;
    int x = 0;
    for(int i=0;i*i<=m;i++) x = i;
    vector<vector<int> > g(n,vector<int>(n,INF));
    g[0][0] = 0;
    queue<pair<P,int>> q;
    int depth = 0;
    q.push({P(0,0),depth});
    while(!q.empty()){
        auto [pos,depth] = q.front(); q.pop();
        auto [i,j] = pos;
        g[i][j] = depth;
        for(int s = -x;s<=x;s++){
            for(int t = -x;t<=x;t++){
                if(s*s+t*t != m) continue;
                if(i+s < 0 || j+t < 0 || i+s >= n || j+t >= n) continue;
                if(g[i+s][j+t] != INF) continue;
                q.push({P(i+s,j+t),depth+1});
            }
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