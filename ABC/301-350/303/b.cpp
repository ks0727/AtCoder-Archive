#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int> > a(m,vector<int>(n));
    rep(i,m){
        rep(j,n){
            cin >> a[i][j];
        }
    }
    vector<vector<bool> > pair(n,vector<bool>(n));
    rep(i,m){
        rep(j,n-1){
            int person1 = a[i][j];
            int person2 = a[i][j+1];
            person1--; person2--;
            pair[person1][person2] = true;
            pair[person2][person1] = true;
        }
    }
    int ans = 0;
    rep(i,n){
        rep(j,n){
            if(i == j) continue;
            if(!pair[i][j]) ans++;
        }
    }
    ans /= 2;
    cout << ans << endl;
    return 0;
}