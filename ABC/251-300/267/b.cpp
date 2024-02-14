#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    string s;
    cin >> s;
    if(s[0] == '1'){ //ピン１が残っていたらだめ
        cout << "No" << endl;
        return 0;
    }
    vector<vector<int> > g(7);
    g[0].push_back(6);
    g[1].push_back(3);
    g[2].push_back(7);
    g[2].push_back(1);
    g[3].push_back(4);
    g[3].push_back(0);
    g[4].push_back(8);
    g[4].push_back(2);
    g[5].push_back(5);
    g[6].push_back(9);
    bool ans = false;
    rep(i,7){
        rep(j,7){
            if(i == j) continue;
            bool ok1 = false;
            bool ok2 = false;
            for(int x : g[i]){
                if(s[x] == '1'){ //i列目のピンのうち倒れているものがあったら
                    ok1 = true;
                }
            }
            if(!ok1) continue;
            for(int x : g[j]){
                if(s[x] == '1') ok2 = true;
            }
            if(!ok2) continue;
            bool ng = false;
            for(int k=i+1;k<j;k++){ //iとj列目の間にあるのがk列目
                for(int x : g[k]){ //k列目のピンを全て調べる
                    if(s[x] == '1'){ //もし残っているものがあったらダメ
                        ng = true;
                        break;
                    }
                }
                if(!ng) ans = true;
            }
        }
    }
    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}