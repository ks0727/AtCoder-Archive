#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using P = pair<int,int>;
const int di[] = {1,0,-1,0};
const int dj[] = {0,1,0,-1};

int main(){
    int h,w;
    cin >> h >> w;
    vector<string> c(h);
    rep(i,h) cin >> c[i];
    P start = P(-1,-1);
    bool found = false;
    rep(i,h){
        if(found) break;
        rep(j,w){
            if(c[i][j] == 'S'){
                start = P(i,j);
                found = true;
                break;
            }
        }
    }
    vector<vector<int> > visited(h,vector<int>(w,-1));
    visited[start.first][start.second] = 0;
    auto dfs = [&](auto dfs, P pos, int depth)->void{
        auto [i,j] = pos;
        visited[i][j] = depth;
        rep(d,4){
            int ni = i + di[d], nj = j+dj[d];
            if(ni < 0 || nj < 0 || ni >= h || nj >= w) continue;
            if(visited[ni][nj] != -1) continue;
            if(c[ni][nj] == '#') continue;
            dfs(dfs,P(ni,nj),depth+1);
        }
    };
    dfs(dfs,start,0);
    bool ans = false;
    rep(i,4){
        auto [si,sj] = start;
        int ni = si+di[i];
        int nj = sj+dj[i];
        if(ni < 0 || nj < 0 || ni >= h || nj >= w) continue;
        if(visited[ni][nj] >= 3) ans = true;
    }
    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}