#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using P = pair<int,int>;
const int dj[] = {1,0,-1,0};
const int di[] = {0,1,0,-1};

int main(){
    int n;
    cin >> n;
    vector<vector<int> > g(n,vector<int>(n));
    vector<vector<bool> > visited(n,vector<bool>(n));
    visited[0][0] = true;
    visited[(n+1)/2-1][(n+1)/2-1] = true;
    auto dfs = [&](auto dfs,P pos, int num)->void{
        if(num >= n*n-1) return;
        auto [i,j] = pos;
        visited[i][j] = true;
        rep(d,4){
            int ni = i+di[d];
            int nj = j+dj[d];
            if(ni < 0 || nj < 0 || ni >= n || nj >= n) continue;
            if(visited[ni][nj]) continue;
            while(true){
                num++;
                if(num >= n*n-1) return;
                visited[ni][nj] = true;
                g[ni][nj] = num;
                ni += di[d];
                nj += dj[d];
                if(ni < 0 || nj < 0 || ni >= n || nj >= n) break;
                if(visited[ni][nj]) break;
            }
            dfs(dfs,P(ni-di[d],nj-dj[d]),num);
        }
    };
    dfs(dfs,P(0,0),0);
    rep(i,n){
        rep(j,n){
            if(i == (n+1)/2-1 && j == (n+1)/2-1){
                cout << 'T' << ' ';
            }else{
                cout << g[i][j]+1 << ' ';
            }
        }
        cout << '\n';
    }
    return 0;
}