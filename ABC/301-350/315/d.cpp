#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int H,W;
    cin >> H >> W;
    vector<string> board(H);
    vector<pair<int,int> > existIndex;
    int ans = 0;
    rep(i,H) cin >> board.at(i);
    rep(i,H){
        rep(j,W){
                char target = board[i][j];
                for(int k=1;k<W;k++){
                    if(target == board[i][k]){
                        board[i][k] = '.';
                        existIndex.push_back(make_pair(i,j));
                    }
            }
        }
    }
    rep(i,W){
        rep(j,H){
            if(board[i][j] == '.') continue;
            else{
                char target = board[i][j];
                for(int k=1;k<H;k++){
                    if(target == board[i][k]){
                        board[i][k] = '.';
                        existIndex.push_back(make_pair(i,j));
                    }
                }
            }
        }
    }
    for(int i=0;i<existIndex.size();i++){
        board[existIndex[i].first][existIndex[i].second] = '.';
    }
    rep(i,H){
        rep(j,W){
            cout << board[i][j];
            if(board[i][j] != '.') ans++;
            if(j == W-1) cout << endl;
        }
    }
    cout << ans << endl;
}