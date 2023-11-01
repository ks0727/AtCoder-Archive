#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using P = pair<int,int>;

const int di[] = {-1,0,1,0};
const int dj[] = {0,-1,0,1};

int main(){
    int n,m;
    cin >> n >> m;
    vector<string> s(n);
    rep(i,n) cin >> s[i];

    vector<vector<bool> > visited(n,vector<bool>(m));
    vector<vector<bool> > passed(n,vector<bool>(m));

    queue<P> q;
    q.emplace(1,1);
    visited[1][1] = true;
    passed[1][1] = true;
    while(!q.empty()){
        auto [i,j] = q.front();
        q.pop();
        rep(v,4){
            int ni = i,nj = j;
            while (s[ni][nj] == '.') //グリッドの座標が氷(.)である間は継続
            {
                passed[ni][nj] = true;
                ni += di[v];
                nj += dj[v];
            }
            ni -= di[v];
            nj -= dj[v];
            if(visited[ni][nj]) continue;
            visited[ni][nj] = true;
            q.emplace(ni,nj);
        }
    }
    cout << "-----------------------------" << endl;
    cout << endl;
    int ans = 0;
    rep(i,n)rep(j,m){
        if(passed[i][j]) ans++;
    }
    rep(i,n)rep(j,m){
        if(passed[i][j]) s[i][j] = '*';
    }
    rep(i,n) cout << s[i] << endl;
    cout << ans << endl;
    return 0;
}
