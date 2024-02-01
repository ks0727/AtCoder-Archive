#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using P = pair<int,int>;

int main(){
    int n,m;
    cin >> n >> m;
    vector<P> dij;
    for(int di =-n;di<n;di++){
        for(int dj = -n;dj<n;dj++){
            if(di*di+dj*dj == m){
                dij.emplace_back(di,dj);
            }
        }
    }
    const int INF = 1001001001;
    vector<vector<int> > dist(n,vector<int>(n,INF));
    queue<P> q;
    auto push = [&](int i,int j, int d){
        if(dist[i][j] != INF) return;
        if(i < 0 || j < 0 || i >= n ||j >= n) return;
        dist[i][j] = d;
        q.emplace(i,j);
    };
    push(0,0,0);
    while(!q.empty()){
        auto [i,j] = q.front(); q.pop();
        for(auto [di,dj] : dij){
            push(i+di,j+dj,dist[i][j]+1);
        }
    }
    rep(i,n){
        rep(j,n){
            int d = dist[i][j];
            if(d == INF) d = -1;
            cout << d << ' ';
        }
        cout << endl;
    }
    return 0;
}