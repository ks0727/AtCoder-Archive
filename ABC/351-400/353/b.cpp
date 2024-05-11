#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    int now = 0;
    int ans = 0;
    rep(i,n){
        if(a[i] <= k - now){
            now += a[i];
        }else{
            ans++;
            now = a[i];
        }
    }
    cout << ans+1 << endl;
    return 0;
}