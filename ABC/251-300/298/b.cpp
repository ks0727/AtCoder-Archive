#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    cin >> n;
    vector<vector<int> > a(n,vector<int>(n)),b(n,vector<int>(n));
    rep(i,n)rep(j,n) cin >> a[i][j];
    rep(i,n)rep(j,n) cin >> b[i][j];
    bool ans = false;
    rep(cnt,4){
        bool ok = true;
        vector<vector<int> > changed(n,vector<int>(n));
        rep(i,n)rep(j,n){
            changed[i][j] = a[n-j-1][i];
            if(a[i][j] == 1){
                if(b[i][j] != 1) ok = false;
                continue;
            }
            if(i == n-1 && j == n-1 && ok) ans = true;
        }
        rep(i,n)rep(j,n) a[i][j] = changed[i][j];
    }
    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}