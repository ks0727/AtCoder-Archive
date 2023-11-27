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
    bool update = true;
    vector<bool> dr(h),dc(w);
    queue<int> deleted_row,deleted_col;
    while(update){
        update = false;
        int kind = 0; int tot = 0;
        rep(i,h){
            if(dr[i]) continue;
            rep(j,26){
                if(row[i][j] == 0) continue;
                kind++; tot += row[i][j];
            }
            if(kind == 1 && tot >= 2){
                update = true;
                dr[i] = true;
                deleted_row.push(i);
            }
        }
        kind = 0; tot = 0;
        rep(i,w){
            if(dc[i]) continue;
            rep(j,26){
                if(col[i][j] == 0) continue;
                kind++; tot += col[i][j];
            }
            if(kind == 1 && tot >= 2){
                update = true;
                dc[i] = true;
                deleted_col.push(i);
            }
        }
        while(!deleted_row.empty()){
            int delete_r = deleted_row.front(); deleted_row.pop();
            int target = c[delete_r][0] - 'a';
            rep(j,w){
                if(col[j][target] != 0) col[j][target]--;
            }
        }
        while(!deleted_col.empty()){
            int delete_c = deleted_col.front(); deleted_col.pop();
            int target = c[0][delete_c] - 'a';
            rep(i,h){
                if(row[i][target] != 0) row[i][target]--;
            }
        }
    }
    int ans = 0;
    rep(i,h){
        rep(j,w){
            if(!dr[i] && !dc[j]){
                ans++;
                cout << c[i][j]<<' ';
            }else{
                cout << '.' << ' ';
            }
        }
        cout << endl;
    }
    cout << ans << endl;
    return 0;
}