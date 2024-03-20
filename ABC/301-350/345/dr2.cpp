#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using P = pair<int,int>;

int main(){
    int n,h,w;
    cin >> n >> h >> w;
    vector<P> tiles(n);
    rep(i,n) cin >> tiles[i].first >> tiles[i].second;
    //vector<vector<bool> > exist(h,vector<bool>(w));
    auto dfs = [&](auto dfs,vector<vector<bool> > board,vector<bool> used)->bool{
        int si = -1, sj = -1;
        bool found = false;
        rep(i,h){
            if(found) break;
            rep(j,w){
                if(!board[i][j] && si == -1){
                    si = i; sj = j;
                    found = true;
                    break;
                }
            }
        }
        if(si == -1) return true;
        rep(ri,n){
            if(used[ri]) continue;
            auto [ch,cw] = tiles[ri];
            rep(k,2){
                swap(ch,cw);
                bool ok = true;
                if(si+ch > h || sj + cw > w) continue;
                rep(i,ch)rep(j,cw){
                    if(board[si+i][sj+j]) ok = false;
                } 
                if(!ok) continue;
                rep(i,ch)rep(j,cw) board[si+i][sj+j] = true;
                used[ri] = true;
                if(dfs(dfs,board,used)) return true;
                rep(i,ch)rep(j,cw) board[si+i][sj+j] = false;
                used[ri] = false;
            }
        }
        return false;
    };
    if(dfs(dfs,vector<vector<bool> >(h,vector<bool>(w)),vector<bool>(n))){
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
    return 0;
}