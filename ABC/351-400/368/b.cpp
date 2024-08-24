#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    int ans = 0;
    while(true){
        ans++;
        sort(a.rbegin(),a.rend());
        a[0]--; a[1]--;
        int cnt = 0;
        rep(i,n) if(a[i] > 0) cnt++;
        if(cnt <= 1) break;
    }
    cout << ans << endl;
    return 0;
}