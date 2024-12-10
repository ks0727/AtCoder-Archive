#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using T = tuple<int,int,int>;
const int di[] = {1,0,-1,0};
const int dj[] = {0,-1,0,1};
int main(){
    int h,w,d;
    cin >> h >> w >> d;
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    priority_queue<T,vector<T> > q;
    vector<vector<int> > grid(h,vector<int>(w,-1));
    rep(i,h)rep(j,w){
        if(s[i][j] == 'H'){
            grid[i][j] = d;
            q.emplace(d,i,j);
        }
    }
    while(!q.empty()){
        auto [c,i,j] = q.top(); q.pop();
        rep(v,4){
            int ni = i+di[v];
            int nj = j+dj[v];
            if(ni < 0 || nj < 0 || ni >= h || nj >= w) continue;
            if(s[ni][nj] == '#') continue;
            if(c-1 > grid[ni][nj]){
                grid[ni][nj] = c-1;
                q.emplace(c-1,ni,nj);
            }
        }
    }
    int ans = 0;
    rep(i,h)rep(j,w){
        if(grid[i][j] >= 0) ans++;
    }
    cout << ans << endl;
    return 0;
}