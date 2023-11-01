#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> ans;
    rep(i,n) cin >> a[i];
    rep(i,n){
        if(a[i] % 2 == 0) ans.push_back(a[i]);
    }
    int size = ans.size();
    rep(i,size) cout << ans[i] << ' ';
    return 0;
}