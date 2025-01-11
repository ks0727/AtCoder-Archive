#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using P = pair<int,int>;
const int di[] = {1,0,-1,0};
const int dj[] = {0,-1,0,1};
int main(){
    int h,w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    int si=-1,sj=-1,gi=-1,gj=-1;
    rep(i,h)rep(j,w){
        if(s[i][j] == 'S'){
            si = i;
            sj = j;
        }
        else if(s[i][j] == 'G'){
            gi = i;
            gj = j;
        }
    }
    const int INF = 1001001001;
    vector<vector<int> > visited_v(h,vector<int>(w,INF)),visited_h(h,vector<int>(w,INF));
    visited_v[si][sj] = 0;
    visited_h[si][sj] = 0;
    queue<P> q;
    q.emplace(si,sj);
    while(!q.empty()){
        auto [i,j] = q.front(); q.pop();
        rep(d,4){
            int ni = i+di[d]; int nj = j+dj[d];
            if(ni < 0 || nj < 0 || ni >= h || nj >= w) continue;
            if(s[ni][nj] == '#') continue;
            if(d == 0 || d == 2){
                if(visited_v[ni][nj] != INF) continue;
                if(visited_h[i][j] == INF) continue;
                visited_v[ni][nj] = visited_h[i][j] + 1;
                q.emplace(ni,nj);
            }
            else if(d == 1 || d == 3){
                if(visited_h[ni][nj] != INF) continue;
                if(visited_v[i][j] == INF) continue;
                visited_h[ni][nj] = visited_v[i][j] + 1;
                q.emplace(ni,nj);
            }
        }
    }
    int ans = min(visited_h[gi][gj],visited_v[gi][gj]);
    if(ans == INF) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}