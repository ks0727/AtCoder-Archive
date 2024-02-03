#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using P = pair<int,int>;
int di[] = {1,0,-1,0};
int dj[] = {0,1,0,-1};
int main(){
    int n;
    cin >> n;
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    int i1=-1,i2=-1,j1=-1,j2=-1;
    bool done = false;
    rep(i,n){
        if(done) break;
        rep(j,n){
            if(i1 == -1 && s[i][j] == 'P'){
                i1 = i; j1 = j;
                s[i][j] = '.';
            }else if(i1 != -1 && s[i][j] == 'P'){
                i2 = i; j2 = j;
                done = true;
                s[i][j] = '.';
                break;
            }
        }
    }
    P pos1 = P(i1,j1);
    P pos2 = P(i2,j2);
    vector<vector<bool> > seen1(n,vector<bool>(n)),seen2(n,vector<bool>(n));
    seen1[i1][j1] = true;
    seen2[i2][j2] = true;
    auto dfs = [&](auto dfs, P pos1, P pos2,int d)->bool{
        seen1[pos1.first][pos1.second] = true;
        seen2[pos2.first][pos2.second] = true;
        while(1){
            if()
        }
    };
}