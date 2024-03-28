#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using P = pair<int,int>;
using T = tuple<int,int,int,int>;
const int di[] = {1,0,-1,0};
const int dj[] = {0,1,0,-1};

int dist[60][60][60][60];

int main(){
    int n;
    cin >> n;
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    const int INF = 1001001001;
    rep(i,60)rep(j,60)rep(k,60)rep(l,60) dist[i][j][k][l] = INF;
    int a=-1,b=-1,c=-1,d=-1;
    rep(i,n){
        rep(j,n){
            if(s[i][j] == 'P' && a == -1){
                a = i; b = j;
                s[i][j] = '.';
            }
            if(s[i][j] == 'P' && a != -1){
                c = i; d = j;
                s[i][j] = '.';
            }
        }
    }
    queue<T> q;
    q.emplace(a,b,c,d);
    dist[a][b][c][d] = 0;
    auto f = [&](int e, int f, int v){
        int ne = e + di[v]; int nf = f + dj[v];
        if(ne < 0 || nf < 0 || ne >= n || nf >= n) return P(e,f);
        if(s[ne][nf] == '#') return P(e,f);
        return P(ne,nf);
    };
    while(!q.empty()){
        auto [x,y,z,w] = q.front(); q.pop();
        rep(k,4){
            P np1 = f(x,y,k);
            P np2 = f(z,w,k);
            int nx = np1.first; int ny = np1.second;
            int nz = np2.first; int nw = np2.second;
            if(dist[nx][ny][nz][nw] != INF) continue;
            dist[nx][ny][nz][nw] = dist[x][y][z][w] + 1;
            q.push(T(nx,ny,nz,nw));
        }
    }
    int ans = INF;
    rep(i,n)rep(j,n) ans = min(ans,dist[i][j][i][j]);
    if(ans == INF) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}