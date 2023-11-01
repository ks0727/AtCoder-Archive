#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using P = pair<int,int>;

vector<int> dx = {1,0,-1,0};
vector<int> dy = {0,-1,0,1};

int main(){
    int r,c;
    cin >> r >> c;
    int sx,sy,gx,gy;
    cin >> sy >> sx >> gy >> gx;
    sy--; sx--;
    gy--; gx--;
    vector<string> grid(r);
    vector<vector<int> > dist(r,vector<int>(c,-1));
    rep(i,r) cin >> grid[i];

    queue<P> q;
    dist[sx][sy] = 0;
    q.push(make_pair(sx,sy));

    while(!q.empty()){
        auto [x,y] = q.front();
        q.pop();
        rep(v,4){
            if(dist[x+dx[v]][y+dy[v]] != -1 || grid[x+dx[v]][y+dy[v]] == '#') continue;
            q.push(make_pair(x+dx[v],y+dy[v]));
            dist[x+dx[v]][y+dy[v]] = dist[x][y] + 1;
        }
    
    cout << dist[gy][gx] << endl;
}