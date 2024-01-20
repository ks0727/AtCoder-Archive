#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using P = pair<int,int>;

int di[] = {1,0,-1,0};
int dj[] = {0,1,0,-1};
int main(){
    int h,w;
    cin >> h >> w;
    vector<string> c(h);
    rep(i,h) cin >> c[i];
    vector<vector<bool> > seen(h,vector<bool>(w));
    P start = P(0,0);
    rep(i,h){
        rep(j,w){
            if(c[i][j] == 'S') start = P(i,j);
        }
    }
    auto dfs =[&](auto dfs,P pos, int dist)->bool{
        auto [i,j] = pos;
        seen[i][j] = true;
        if(dist >= 4 && pos == start) return true;
        rep(d,4){
            int ni = i + di[d]; int nj = j + dj[d];
            if(ni < 0 || nj < 0 || ni >= h || nj >= w) continue;
            if(c[ni][nj] == '#') continue;
            if(seen[ni][nj] && ni != start.first && nj != start.second) continue;
            if(ni == start.first && nj == start.second && dist < 4 ) continue;
            P npos = P(ni,nj);
            dfs(dfs,npos,dist+1);
        }
        return false;
    };
    if(dfs(dfs,start,0)) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}