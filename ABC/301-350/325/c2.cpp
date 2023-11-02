#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using P = pair<int,int>;
const int di[] = {1,1,0,-1,-1,-1,0,1};
const int dj[] = {0,1,1,1,0,-1,-1,-1};

int main(){
    int h,w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    queue<P> q;
    rep(i,h)rep(j,w){
        if(s[i][j] == '#'){
            q.push({i,j});
            while(!q.empty()){
                P pos = q.front(); q.pop();
                rep(d,8){
                    int ni = pos.first+di[d]; int nj = pos.second+dj[d];
                    if(ni < 0 || nj < 0 || ni >= h || nj >= w) continue;
                    if(s[ni][nj] == '#'){
                        if(make_pair(ni,nj) != make_pair(i,j)){
                            s[ni][nj] = '.';
                            q.push({ni,nj});
                        }
                    }
                }
            }
        }
    }
    int ans = 0;
    rep(i,h)rep(j,w){
        if(s[i][j] == '#') ans++;
    }
    cout << ans << endl;
    return 0;
}