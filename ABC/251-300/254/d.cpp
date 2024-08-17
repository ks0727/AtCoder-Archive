#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using ll = long long;

int main(){
    int n;
    cin >> n;
    ll ans = 0;
    for(int i=1;i<=n;i++){
        ll x = (ll)i*i;
        for(int a = 1; a<n; a++){
            if(x%a != 0 ) continue;
            int b = x / a;
            if(b <= a || b > n) continue; // a < b
            ans++;
        }
    }
    ans *= 2;
    ans += n;
    cout << ans << endl;
    return 0;
}