#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int h1,w1;
    cin >> h1 >> w1;
    vector a(h1,vector<int>(w1));
    rep(i,h1)rep(j,w1) cin >> a[i][j];
    int h2,w2;
    cin >> h2 >> w2;
    vector b(h2,vector<int>(w2));
    rep(i,h2)rep(j,w2) cin >> b[i][j];
    rep(hs,1<<h1)rep(ws,1<<w1){
        vector<int> is,js;
        rep(i,h1){
            if(hs &(1<<i)){//hsのi桁めをとる
                is.push_back(i);
            }
        }
        rep(j,h2){
            if(ws&(1<<j)) js.push_back(j);
        }
        if(is.size() != h2) continue;
        if(js.size() != w2) continue;
        vector c(h2,vector<int>(w2));
        rep(i,h2)rep(j,w2) c[i][j] = a[is[i]][js[j]];
        if(b == c) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" <<endl;
    return 0;
}