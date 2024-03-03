#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using P = pair<int,int>;
const int di[] = {0,1,0,-1};
const int dj[] = {1,0,-1,0};

int main(){
    int r,c;
    cin >> r >> c;
    c--; r--;
    vector<vector<bool> > visited(15,vector<bool>(15));
    vector<string> grid(15);
    rep(i,15){
        rep(j,15) grid[i]+='.';
    }
    int ci = 0; int cj = 0;
    bool b = 1;
    while(!visited[ci][cj]){
        rep(d,4){
            int ni = ci, nj = cj;
            while(ni >= 0 && nj >= 0 && ni < 15 && nj < 15){
                if(b) grid[ni][nj] = 'b';
                else grid[ni][nj] = 'w';
                visited[ni][nj] = true;
                ni += di[d]; nj += dj[d];
                if(ni < 0 || nj < 0 || ni>= 15 || nj >=15) break;
                if(visited[ni][nj]) break;
            }
            ni -= di[d]; nj -= dj[d];
            if(d != 3){
                ci = ni; cj = nj;
            }
            if(d == 3){
                ci = ni+di[0]; cj = nj+dj[0];
            } 
        }
        b ^= 1;
    }
    if(grid[r][c] == 'b') cout << "black" << endl;
    else cout << "white" << endl;
    return 0;
}