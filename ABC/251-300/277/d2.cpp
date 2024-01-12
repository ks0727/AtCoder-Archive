#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    ll sum = 0;
    rep(i,n) sum += (ll)a[i];
    sort(a.begin(),a.end());
    ll ans = sum;
    bool isdone = false;
    rep(i,n){
        if(isdone) break;
        ll now = sum;
        now -= a[i];
        while((a[i] == a[(i+1)%n] || (a[i]+1)%m == a[(i+1)%n]) && i+1 < a.size()){
            i++;
            now -= a[i];
            if(a[i] == m-1){
                i = 0;
                isdone = true;
            }
        }
        ans = min(ans,now);
    }
    cout << ans << endl;
    return 0;
}