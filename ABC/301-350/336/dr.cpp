#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<int> fw(n),bw(n);
    fw[0] = bw[n-1] = 1;
    for(int i=1;i<(n);i++){
        fw[i] = min(fw[i-1]+1,a[i]);
    }
    for(int i=n-2;i>=0;i--){
        bw[i] = min(bw[i+1]+1,a[i]);
    }
    int ans = 0;
    rep(i,n){
        int mx = min(fw[i],bw[i]);
        ans = max(ans,mx);
    }
    cout << ans << endl;
    return 0;
}