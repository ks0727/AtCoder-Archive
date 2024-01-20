#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    sort(a.begin(),a.end());
    if(a.size() == 1){
        cout << 0 << endl;
        return 0;
    }
    ll sum = 0;
    rep(i,n) sum += a[i];
    ll ans = sum - a[0];
    ll now = sum - a[0];
    int prev = a[0];
    bool done = false;
    int seen = 0;
    for(int i=1;i<n*2;i++){
        if(a[i%n] == prev || a[i%n] == (prev+1)%m){
            now -= a[i%n];
            seen++;
        }else{
            if(i >= n) break;
            seen = 0;
            now = sum - a[i%n];
        }
        prev = a[i%n];
        ans = min(now,ans);
        if(seen >= n-1) break;
    }
    cout << ans << endl;
    return 0;
}