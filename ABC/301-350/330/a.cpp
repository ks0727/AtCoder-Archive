#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n,l;
    cin >> n >> l;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    int ans = 0;
    rep(i,n){
        if(a[i] >= l) ans++;
    }
    cout << ans << endl;
    return 0;
}