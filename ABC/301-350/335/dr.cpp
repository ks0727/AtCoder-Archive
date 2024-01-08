#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using P = pair<int,int>;

const int di[] = {1,0,-1,0};
const int dj[] = {0,1,0,-1};

int main(){
    int n;
    cin >> n;
    vector<vector<bool> > visited(n,vector<bool>(n));
    vector<vector<int> > g(n,vector<int>(n));
    visited[0][0] = true;
    visited[(n+1)/2-1][(n+1)/2-1] = true;
    int now = 0;
    auto dfs = [&](auto dfs, P p)->void{
        if(now >= n * n) return;
        auto [i,j] = p;
        rep(d,4){
            int ni = i + di[d]; int nj = j + dj[d];
            if(ni < 0 || nj < 0 || ni >= n || nj >= n) continue;
            if(visited[ni][nj]) continue;
            while(true){
                now++;
                if(now >= n * n) break;
                if(ni < 0 || nj < 0 || ni >= n || nj >= n) break;
                if(visited[ni][nj]) break;
                visited[ni][nj] = true;
                g[ni][nj] = now;
                ni += di[d]; nj += dj[d];
            }
            ni -= di[d]; nj -= dj[d]; now--;
            dfs(dfs,P(ni,nj));
        }
    };
    dfs(dfs,P(0,0));
    rep(i,n){
        rep(j,n){
            if(i == (n+1)/2-1 && j == (n+1)/2-1){
                cout << 'T' << ' '; 
            }else{
                cout << g[i][j] + 1<< ' ';
            }
        }
        cout << '\n';
    }
    return 0;
}