#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int r,c;
    cin >> r >> c;
    vector<string> b(r);
    rep(i,r) cin >> b[i];
    vector<vector<bool> > exploded(r,vector<bool>(c));
    rep(i,r){
        rep(j,c){
            if(isdigit(b[i][j])){
                rep(ii,r){
                    rep(jj,c){
                        if(abs(i - ii) + abs(j - jj) <= b[i][j] - '0'){
                            exploded[ii][jj] = true;
                        }
                    }
                }
            }
        }
    }
    rep(i,r){
        rep(j,c){
            if(exploded[i][j]) cout << '.';
            else cout << b[i][j];
        }
        cout << endl;
    }
    return 0;
}