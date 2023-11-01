#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> a(m);
    vector<int> ans(n);
    rep(i,m) cin >> a[i];
    ans[n-1] = 0;
    for(int i = n-1;i >= 1;i--){
        int key = i;
        int index = *lower_bound(a.begin(),a.end(),key);
        ans[i-1] = index - i;
    }
    rep(i,n) cout << ans[i] << endl;
    return 0;
}