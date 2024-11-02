#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    cin >> n;
    vector<vector<int> > a(n,vector<int>(n));
    rep(i,n)rep(j,n){
        char in;
        cin >> in;
        a[i][j] = in - '0';
    }
    vector<vector<int> > b(n,vector<int>(n));
    b = a;
    rep(i,n){
        rep(j,n){
            if(i != 0 && i != n-1 && j != 0 && j != n-1) continue;
            if(i == 0 && j != n-1){
                b[i][j+1] = a[i][j];
                continue;
            } 
            if(i != n-1 && j == n-1) {
                b[i+1][j] = a[i][j];
                continue;
            }
            if(i == n-1 && j != 0) {
                b[i][j-1] = a[i][j];
                continue;
            }
            if(i != 0 && j == 0) b[i-1][j] = a[i][j];
        }
    }
    rep(i,n){
        rep(j,n){
            cout << b[i][j];
        }
        cout << endl;
    }
    return 0;
}
