#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
//やっていることは、消す場所を保存しておいて最後に消さない場所を数え上げる
int main(){
    int h,w;
    cin >> h >> w;
    vector<string> c(h);
    vector a(h, vector<int>(w));
    rep(i,h){
        rep(j,w){
            a[i][j] = c[i][j] - 'a'; //ここでアルファベットを数値に変換
        }
    }
    rep(i,h) cin >> c[i];
    vector row(h, vector<int>(m)); //mはアルファベットのそれぞれの種類で最大26 つまりそれぞれの行にそのアルファベットが何文字入っているかを記録している
    vector col(w, vector<int>(m));
    rep(i,h){
        rep(j,w){
            row[i][a[i][j]]++; //それぞれのアルファベットの数をカウント
            col[j][a[i][j]]++;
        }
    }

    vector<bool> row_deleted(h);　//消されているかのbool変数
    vector<bool> col_deleted(w);

    auto toDelete() = [&](vector<int> x){ //xの中身は[0,3,2,4,1,...4]のように各アルファベットの個数の情報が入る
        int tot=0, k=0;
            rep(j,m){
                tot += x[j];
                if(x[j]) k++; //c++において0が偽で0以外は真だから0出なければ種類のカウントをあげるということができる
            }
            return tot >= 2 && k==1;　//そこの列/行に『合計2個以上のクッキーがありかつその種類が１種類であるかどうか』　を返す
    };

    auto del = [&](int i,int j){
        if(row_deleted[i] || col_deleted[j]) return; //そこのアルファベットがすでに削除されているなら何もしない
        row[i][a[i][j]]--; //アルファベットを削除し、カウントを１減らしていく
        col[j][a[i][j]]--;
    };

    bool upd = true;
    while(upd){
        upd = false;
        vector<int> del_row,del_col;
        rep(i,h){
            if(row_deleted[i]) continue;
            if(toDelete(row[i])) del_row.push_back(i);
        }
        rep(i,w){
            if(row_deleted[i]) continue;
            if(toDelete(col[i])) del_col.push_back(i);
        }
        for(int i: del_row){
            rep(j,h) del(i,j);
            row_deleted[i] = true;
            upd = true;
        }
        for(int i: del_col){
            rep(j,w) del(i,j);
            col_deleted[i] = true;
            upd = true;
        }
    }
    int ans = 0;
    rep(i,h){
        rep(j,w){
            if(row_deleted[i] || col_deleted[j]) continue;
            ans++; //削除された情報が残っていないなら、カウント         
        }
    }
    cout << ans << endl;
}