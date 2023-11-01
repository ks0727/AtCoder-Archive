#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define ALPHA 26

int main(){
    int h,w;
    cin >> h >> w;
    vector<string> c(h);
    rep(i,h) cin >> c[i];
    vector<vector<int> > a(h,vector<int>(w));
    rep(i,h){
        rep(j,w){
            a[i][j] = c[i][j] - 'a';
        }
    }
    vector<vector<int> > row(h,vector<int>(ALPHA)),col(w,vector<int>(ALPHA));
    rep(i,h){
        rep(j,w){
            row[i][a[i][j]]++;
            col[j][a[i][j]]++;
        }
    }
    rep(i,h){
        rep(j,ALPHA){
            cout << row[i][j];
        }
    }
    cout << endl;
    rep(i,w){
        rep(j,ALPHA){
            cout << col[i][j];
        }
    }
    cout << endl;
    vector<bool> row_deleted(h);
    vector<bool> col_deleted(w);
    bool update = true;
    while(update){
        //その行・列の種類数を取得
        update = false;
        vector<int> row_kinds(h),col_kinds(w);
        rep(i,h){
            rep(j,w){
                if(row[i][j] != 0) row_kinds[i]++;
                if(col[j][i] != 0) col_kinds[j]++;
            }
        }
        //もしもその行・列に同じ種類の文字が二つ以上あればその文字を削除
        rep(i,h){
            rep(j,ALPHA){
                if(row[i][j] >= 2){
                    row[i][j] = 0;
                }
            }
        }
        rep(i,w){
            rep(j,ALPHA){
                if(col[i][j] >= 2){
                    col[i][j] = 0;
                }
            }
        }
        //もしもその行・列に一つも文字がなければその行・列は削除(row[i][j]の値が全て0の時,i行目は削除ということになる)
        rep(i,h){
            rep(j,ALPHA){
                if(row[i][j] != 0) break;
                if(j == ALPHA-1) row_deleted[i] = true;
            }
        }
        rep(i,w){
            rep(j,ALPHA){
                if(col[i][j] != 0) break;
                if(j == ALPHA-1) col_deleted[i] = true;
            }
        }

        //updateの処理(それぞれのアルファベットが一種類ずつになったらupdateをしなくする)
        bool update_row = false;
        bool update_col = false;
        rep(i,h){
            rep(j,w){
                if(row[i][j] >= 2) update_row = true;
                if(col[j][i] >= 2) update_col = true;
            }
        }
        if((update_row == false) && (update_col == false)) update = false;
    }
    int ans = 0;
    rep(i,h){
        rep(j,w){
            if(!row_deleted[i] && !col_deleted[j]) ans++;
            else c[i][j] = '.';
        }
    }
    rep(i,h){
        rep(j,w){
            cout << c[i][j];
        }
        cout << endl;
    }
    cout << ans << endl;
}