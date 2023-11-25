#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int h,w;
    cin >> h >> w;
    vector<string> c(h);
    rep(i,h) cin >> c[i];
    vector<bool> exist_h(h,true),exist_w(w,true);
    while(true){
        vector<int> row,col;
        rep(i,h){
            if(!exist_h[i]) continue;
            int erase = 0;
            bool found = false;
            char target = '.';
            for(int j=0;j<(w);j++){
                if(!found && !exist_w[j]) continue;
                if(!found && exist_w[j]){
                    found = true;
                    target = c[i][j];
                    continue;
                }
                if(target != c[i][j] && exist_w[j]) break;
                if(exist_w[j]) erase++;
                if(j == w-1 && erase >= 2){
                    row.push_back(i);
                }
            }
        }
        rep(j,w){
            if(!exist_w[j]) continue;
            int erase = 0;
            bool found = false;
            char target = '.';
            for(int i = 0;i<(h);i++){
                if(!found && !exist_h[i]) continue;
                if(!found && exist_h[i]){
                    found = true;
                    target = c[i][j];
                    continue;
                }
                if(target != c[i][j] && exist_h[i]) break;
                if(exist_h[i]) erase++;
                if(i == h-1 && erase >= 2){
                    col.push_back(j);
                }
            }
        }
        if(row.size() == 0 && col.size() == 0) break;
        rep(i,row.size()){
            exist_h[row[i]] = false;
        }
        rep(j,col.size()){
            exist_w[col[j]] = false;
        }
    }
    int ans = 0;
    rep(i,h){
        rep(j,w){
            if(exist_h[i] && exist_w[j]) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}