#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    cin >> n;
    vector<int> a(n*7);
    rep(i,7*n) cin >> a[i];
    vector<int>  ans;
    rep(i,n){
        int tot = 0;
        rep(j,7){
            tot += a[(i*7)+j];
        }
        ans.push_back(tot);
    }
    rep(i,n) cout << ans[i] << ' ';
    return 0;
}