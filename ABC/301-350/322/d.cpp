#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

vector<vector<bool> > rotate(vector<vector<bool> > grid){
    vector<vector<bool> > rotated(4,vector<bool>(4));
    rep(i,4){
        rep(j,4){
            rotated[i][j] = grid[3-j][i];
        }
    }
    return rotated;
}
int main(){
    vector<string> s1(4);
    vector<string> s2(4);
    vector<string> s3(4);
    rep(i,4) cin >> s1[i];
    rep(i,4) cin >> s2[i];
    rep(i,4) cin >> s3[i];
    vector<vector<bool> > poly1(4,vector<bool>(4));
    vector<vector<bool> > poly2(4,vector<bool>(4));
    vector<vector<bool> > poly3(4,vector<bool>(4));
    rep(i,4){
        rep(j,4){
            if(s1[i][j] == '#') poly1[i][j] = true;
            if(s2[i][j] == '#') poly2[i][j] = true;
            if(s3[i][j] == '#') poly3[i][j] = true;
        }
    }
    
}