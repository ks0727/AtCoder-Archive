#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    int n;
    cin >> n;
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    
    vector<vector<vector<int>>> in(n, vector<vector<int>>(26));
    vector<vector<vector<int>>> out(n, vector<vector<int>>(26));
    rep(u,n){
        rep(v,n){
            char c = s[u][v];
            if(c == '-') continue;
            out[u][c-'a'].push_back(v);
            in[v][c-'a'].push_back(u);
        }
    }
    const int INF = 1e9;
    vector<vector<int> > dist(n, vector<int>(n, INF));
    queue<pair<int,int> > q;
    rep(i,n){
        dist[i][i] = 0;
        q.push({i, i});
    }
    rep(u,n){
        rep(c,26){
            for (int v : out[u][c]){
                if(dist[u][v] > 1){
                    dist[u][v] = 1;
                    q.push({u, v});
                }
            }
        }
    }
    
    while(!q.empty()){
        auto [u, v] = q.front();
        q.pop();
        int d = dist[u][v];
        rep(c,26){
            for (int a : in[u][c]){
                for (int b : out[v][c]){
                    if(d + 2 < dist[a][b]){
                        dist[a][b] = d + 2;
                        q.push({a, b});
                    }
                }
            }
        }
    }
    rep(i,n){
        rep(j,n){
            if(dist[i][j] == INF) cout << -1 << " ";
            else cout << dist[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
