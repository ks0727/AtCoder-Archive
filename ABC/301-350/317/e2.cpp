#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using P = pair<int,int>;
const int di[] = {1,0,-1,0};
const int dj[] = {0,1,0,-1};
int main(){
    int h,w;
    cin >> h >> w;
    vector<string> a(h);
    rep(i,h) cin >> a[i];
    int si=-1,sj=-1;
    int gi=-1,gj=-1;
    vector<vector<bool> > enter(h,vector<bool>(w,true));
    rep(i,h)rep(j,w){
        if(a[i][j] =='S'){
            si = i; sj = j;
            continue;
        }else if(a[i][j] == 'G'){
            gi = i; gj = j;
            continue;
        }else if(a[i][j] == '#'){
            enter[i][j] = false;
            continue;
        }else if(a[i][j] == '.'){
            continue;
        }else{
            int d = -1;
            if(a[i][j] == '>') d = 1;
            else if(a[i][j] == '<') d = 3;
            else if(a[i][j] == 'v') d = 0;
            else d = 2;
            int ni = i, nj = j;
            enter[ni][nj] = false;
            while(true){
                ni += di[d]; nj += dj[d];
                if(ni < 0 || nj < 0 || ni >= h || nj >= w) break;
                if(a[ni][nj] != '.' && a[ni][nj] != 'S' && a[ni][nj] != 'G') break;
                enter[ni][nj] = false;
            }
        }
    }
    queue<P> q;
    q.emplace(si,sj);
    vector<vector<int> > visited(h,vector<int>(w,-1));
    visited[si][sj] = 0;
    while(!q.empty()){
        auto [i,j] = q.front(); q.pop();
        for(int d=0;d<4;d++){
            int ni = i + di[d]; int nj = j + dj[d];
            if(ni < 0 || nj < 0 || ni >= h || nj >= w) continue;
            if(visited[ni][nj] != -1 || !enter[ni][nj]) continue;
            visited[ni][nj] = visited[i][j] + 1;
            q.emplace(ni,nj);
        }
    }
    cout << visited[gi][gj] << endl;
    return 0;
}