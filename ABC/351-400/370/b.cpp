#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    int n; cin >> n;
    vector<vector<int> > a(n,vector<int>(n));
    rep(i,n){
        rep(j,i+1){
            cin >> a[i][j],a[i][j]--;
        }
    }
    int now = 0;
    rep(i,n){
        if(now >= i) now = a[now][i];
        else now = a[i][now];
    }
    cout << now+1 << endl;
    return 0;
}