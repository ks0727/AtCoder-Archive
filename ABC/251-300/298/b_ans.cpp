#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    cin >> n;
    vector<vector<int> > a(n,vector<int>(n));
    vector<vector<int> > b(n,vector<int>(n));
    rep(i,n)rep(j,n) cin >> a[i][j];
    rep(i,n)rep(j,n) cin >> b[i][j];
    rep(ri,4){
        bool ok = true;
        rep(i,n)rep(j,n){
            if(a[i][j] == 1 && b[i][j] == 0) ok = false;
        }
        if(ok){
            cout << "Yes" << endl;
            return 0;
        }
        vector<vector<int> > na(n,vector<int>(n));
        rep(i,n)rep(j,n){
            na[i][j] = a[n-j-1][i];
        }
        a = na;
    }
    cout << "No" << endl;
    return 0;
}