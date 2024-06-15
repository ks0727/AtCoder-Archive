#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> a(n),b(m);
    rep(i,n) cin >> a[i];
    rep(i,m) cin >> b[i];
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    ll ans = 0;
    int now = 0;
    rep(i,m){
        while(now < n && b[i] > a[now]){
            now++;
        }
        if(now == n){
            cout << -1 << endl;
            return 0;
        }
        ans += a[now];
        now++;
    }
    cout << ans << endl;
    return 0;
}