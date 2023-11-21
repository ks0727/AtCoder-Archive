#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using P = pair<int,int>;
const int di[] = {1,0,-1,0};
const int dj[] = {0,1,0,-1};

int main(){
    int n,m;
    cin >> n >> m;
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    vector<vector<bool> > cango(n,vector<bool>(m));
    vector<vector<bool> > seen(n,vector<bool>(m));
    queue<P> q;
    q.push(P(1,1));
    seen[1][1] = true;
    while(!q.empty()){
        auto [i,j] = q.front(); q.pop();
        cango[i][j] = true;
        rep(d,4){
            int ni = i + di[d]; int nj = j+dj[d];
            if(s[ni][nj] == '#') continue;
            if(ni<0 || nj < 0 || ni >= n || nj >=m) continue;
            cango[ni][nj] = true;
            while(true){
                if(ni < 0 || nj < 0 || ni >= n || nj >=m) break;
                if(s[ni][nj] == '#') break;
                cango[ni][nj] = true;
                ni += di[d]; nj += dj[d];
            }
            ni -= di[d]; nj -= dj[d];
            if(seen[ni][nj]) continue;
            seen[ni][nj] = true;
            q.push(P(ni,nj));
        }
    }
    int ans = 0;
    rep(i,n){
        rep(j,m){
            if(cango[i][j] && s[i][j] == '.'){
                s[i][j] = '*';
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}