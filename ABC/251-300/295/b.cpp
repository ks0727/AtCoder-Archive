#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int r,c;
    cin >> r >> c;
    vector<vector<char> > grid(r,vector<char>(c));
    rep(i,r){
        rep(j,c){
            cin >> grid[i][j];
        }
    }
    vector<vector<bool> > exploded(r,vector<bool>(c));
    rep(i,r){
        rep(j,c){
            //if(grid[i][j] == '.') continue;
            //if(grid[i][j] == '#') continue;
            if(isdigit(grid[i][j])) continue;
            int area = grid[i][j] - '0';
            //cout << area << ' ' << grid[i][j]<< endl;
            //exploded[i][j] = true;
            rep(x,r){
                rep(y,c){
                    if(abs(i-x) + abs(j-y) <= area) exploded[x][y] = true;
                }
            }
        }
    }
    rep(i,r){
        rep(j,c){
            if(exploded[i][j]) grid[i][j] = '.';
        }
    }
    rep(i,r){
        rep(j,c){
            cout << grid[i][j];
        }
        cout << endl;
    }
    return 0;
}