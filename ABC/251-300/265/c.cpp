#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using P = pair<int,int>;

const int di[] = {1,0,-1,0};
const int dj[] = {0,1,0,-1};

int main(){
    int h,w;
    cin >> h >> w;
    vector<string> g(h);
    rep(i,h) cin >> g[i];
    map<char,int> mp;
    mp['U'] = 2;
    mp['D'] = 0;
    mp['R'] = 1;
    mp['L'] = 3;
    vector<vector<bool> > visited(h,vector<bool>(w));
    visited[0][0] = true;
    queue<P> q;
    q.emplace(0,0);
    bool ok = true;
    P ans = P(-1,-1);
    while(!q.empty()){
        P now = q.front(); q.pop();
        visited[now.first][now.second] = true;
        char direction = g[now.first][now.second];
        int d = mp[direction];
        int ni = now.first+di[d]; int nj = now.second+dj[d];
        if(ni < 0 || nj < 0 || ni >= h || nj >= w){
            ans = now;
            break;
        }
        if(visited[ni][nj]){
            ok = false;
            break;
        }
        q.emplace(ni,nj);
    }
    if(ok) cout << ans.first+1 << ' ' << ans.second+1 << endl;
    else cout << -1 << endl;
    return 0;
}