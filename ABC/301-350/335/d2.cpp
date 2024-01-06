#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using P = pair<int,int>;
const int di[] = {1,0,-1,0};
const int dj[] = {0,1,0,-1};

int main(){
    int n;
    cin >> n;
    const int INF = 1e9;
    vector<vector<int> > g(n,vector<int>(n));
    vector<vector<bool> > visited(n,vector<bool>(n));
    queue<P> q;
    q.push(P(0,0));
    visited[0][0] = true;
    visited[(n+1)/2-1][(n+1)/2-1] = true;
    int num = 0;
    while(!q.empty()){
        auto [i,j] = q.front(); q.pop();
        g[i][j] = num;
        visited[i][j] = true;
        num++;
        rep(d,4){
            int ni = i + di[d]; int nj = j + dj[d];
            if(ni < 0 || nj < 0 || ni >= n || nj >= n) continue;
            if(visited[ni][nj]) continue;
            q.push(P(ni,nj));
        }
    }
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