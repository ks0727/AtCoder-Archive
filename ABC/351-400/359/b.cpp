#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    cin >> n;
    vector<int> a(n*2);
    rep(i,n*2) cin >> a[i];
    int ans = 0;
    for(int i=1;i<=n;i++){
        rep(j,2*n-2){
            if(a[j] == i && a[j+2] == i) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}