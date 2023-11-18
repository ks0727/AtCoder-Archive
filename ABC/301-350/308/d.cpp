#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using P = pair<int,int>;
const int di[] = {-1,0,1,0};
const int dj[] = {0,-1,0,1};    

int main(){
    int h,w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    string snuke = "snuke";
    bool ok = false;
    vector<vector<bool> > visited(h,vector<bool>(w));
    auto dfs = [&](auto dfs, P pos, int t)->void{
        auto [i,j] = pos;
        visited[i][j] = true;
        rep(d,4){
            int ni = i + di[d]; int nj = j + dj[d];
            if(ni < 0 || nj < 0 || ni >= h || nj >= w) continue;
            if(visited[ni][nj]) continue;
            if(s[ni][nj] == snuke[(t+1)%5]) dfs(dfs,P(ni,nj),t+1);
        }
    };
    if(s[0][0] != 's'){
        cout << "No" << endl;
        return 0;
    }
    dfs(dfs,P(0,0),0);
    if(visited[h-1][w-1]) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}