#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    cin >> n;
    vector<vector<int> > a(n,vector<int>(n));
    rep(i,n)rep(j,n) cin >> a[i][j];
    vector<vector<int> > g(n);
    rep(i,n){
        rep(j,n){
            if(a[i][j] == 1){
                g[i].push_back(j+1);
            }
        }
    }
    rep(i,n){
        rep(j,g[i].size()){
            cout << g[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}