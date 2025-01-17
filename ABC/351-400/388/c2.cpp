#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    int r = 0;
    long long ans = 0;
    rep(l,n){
        while(r<n && a[l]*2 > a[r]){
            r++;
        }
        if(r == l) l++;
        else ans += (n-r);
    }
    cout << ans << endl;
    return 0;
}