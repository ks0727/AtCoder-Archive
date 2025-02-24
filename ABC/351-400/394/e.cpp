#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    int n;
    cin >> n;
    vector<string> c(n);
    rep(i,n) cin >> c[i];
    const int INF = 1e9;
    vector<vector<int> > dist(n,vector<int>(n,INF)); //i->jへのコスト
    queue<pair<int,int> > q;
    rep(i,n)rep(j,n){
        if(i == j){
            dist[i][j] = 0;
            q.emplace(i,i);
        }
        else if(c[i][j] != '-'){
            dist[i][j] = 1;
            q.emplace(i,j);
        } 
    }
    while(!q.empty()){
        auto [i,j] = q.front(); q.pop();
        rep(ii,n){
            rep(jj,n){
                if(c[ii][i] != '-' && c[ii][i] == c[j][jj]){
                    if(dist[ii][jj] > dist[i][j]+2){
                        dist[ii][jj] = dist[i][j]+2;
                        q.emplace(ii,jj);
                    }
                }
            }
        }
    }
    rep(i,n){
        rep(j,n){
            if(dist[i][j] == INF) cout << -1 << ' ';
            else cout << dist[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}