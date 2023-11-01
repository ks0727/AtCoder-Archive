#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i =0;i<(n);i++)

int main(){
    vector<vector<int> > c(3,vector<int>(3));
    int all =0;
    int incident = 0;
    vector<int> dx = {0,1,0,-1};
    vector<int> dy = {1,0,-1,0};
    rep(i,3)rep(j,3) cin >> c[i][j];
    vector<vector<bool> > seen(3,vector<bool>(3));
    int count = 0;
    auto f = [&](auto f,auto seen,auto c,int x,int y) -> void{
        seen[x][y] = true;
        while(true){
            rep(d,4){
                if(seen[x+dx[d]][y+dy[d]]) continue;
                if(x+dx[d] > 2 || x+dx[d] < 0 || y+dy[d] > 2 || y+dy[d] < 0) continue;
                rep(i,3){
                    rep(j,3){
                        if(seen[i][j]) count++;
                    }
                }
                if(count >= 3){
                    rep(i,3)rep(j,3) seen[i][j] = false;
                    count = 0;
                    break;
                }
                if(c[x+dx[d]][y+dy[d]] == c[x][y]) incident++;
                all++;
                cout << x+dx[d] << ' ' << y+dy[d] << endl;
                f(f,seen,c,x+dx[d],y+dy[d]);
            }
        }
    };

    rep(x,3)rep(y,3) f(f,seen,c,x,y);
    double ans = incident / all;
    cout << ans << endl;
}