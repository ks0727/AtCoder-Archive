#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    cin >> n;
    vector<vector<bool> > grid(100,vector<bool>(100));
    rep(i,n){
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        for(int j = a;j<b;j++){
            for(int k=c;k<d;k++){
                grid[j][k] = true;
            }
        }
    }
    int ans = 0;
    rep(i,100){
        rep(j,100){
            if(grid[i][j]) ans++;
        }
    }
    cout << ans << endl;
}