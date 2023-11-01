#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> a(m);
    rep(i,m) cin >> a[i];
    vector<int> ans(n);
    rep(i,m){
        ans[a[i]-1] = 0;
    }
    rep(i,m-1){
        int dif = a[i+1] - a[i];
        int value = a[i];
        while(dif > 0){
            ans[value] = dif;
            value++;
            dif--;
        }
    }
    rep(i,n) cout << ans[i] - 1 << endl;
    return 0;
}