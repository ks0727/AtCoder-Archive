#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using P = pair<int,int>;
vector<int> dx = {1,0,-1,0};
vector<int> dy = {0,-1,0,1};

int main(){
    int n,m;
    cin >> n >> m;
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    queue<P> que;
    vector<vector<bool> > visited(n,vector<bool>(m));
    vector<vector<bool> > passed(n,vector<bool>(m));
    que.push({1,1});
    visited[1][1] = true;
    passed[1][1] = true;
    while(!que.empty()){
        auto [x,y] = que.front();
        que.pop();
        rep(d,4){
            int nx = x, ny = y;
            while(s[nx][ny] == '.'){
                passed[nx][ny] = true;
                nx += dx[d]; ny += dy[d];
            }
            nx -= dx[d]; ny -= dy[d];
            if(visited[nx][ny]) continue;
            visited[nx][ny] = true;
            que.push({nx,ny});
        }
    }
    int ans = 0;
    rep(i,n)rep(j,m){
        if(passed[i][j]) ans++;
    }
    cout << ans << endl;
}