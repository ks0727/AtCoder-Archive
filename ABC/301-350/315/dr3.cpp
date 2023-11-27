#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int h,w;
    cin >> h >> w;
    vector<string> c(h);
    rep(i,h) cin >> c[i];
    vector<vector<int> > row(h,vector<int>(26)),col(w,vector<int>(26));
    rep(i,h){
        rep(j,w){
            row[i][c[i][j]-'a']++;
            col[j][c[i][j]-'a']++;
        }
    }

    vector<bool> dr(h),dc(w);
    auto cnt = [&](vector<int> x){
        int tot = 0, kind = 0;
        rep(k,26){
            tot += x[k];
            if(x[k]) kind++;
        }
        return tot >= 2 && kind==1;
    };

    auto Del = [&](int i, int j){
        if(dr[i] || dc[j]) return;
        row[i][c[i][j]-'a']--;
        col[j][c[i][j]-'a']--;
    };
    bool upd = true;
    while(upd){
        upd = false;
        vector<int> deleted_row,deleted_col;
        rep(i,h){
            if(dr[i]) continue;
            if(cnt(row[i])){
                upd = true;
                deleted_row.push_back(i);
            } 
        }
        rep(i,w){ 
            if(dc[i]) continue;
            if(cnt(col[i])){
                upd = true;
                deleted_col.push_back(i);
            }  
        }
        for(int i : deleted_row){
            rep(j,w) Del(i,j);
            dr[i] = true;
        }
        for(int j : deleted_col){
            rep(i,h) Del(i,j);
            dc[j] = true;
        }
    }

    int ans = 0;
    rep(i,h){
        rep(j,w){
            if(dr[i] || dc[j]) continue;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}