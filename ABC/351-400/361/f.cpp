#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using ll = long long;

int main(){
    ll n;
    cin >> n;
    ll ans = 0;
    vector<bool> seen(n);
    for(ll i = 2;i*i<n;i++){
        if(seen[i]) continue;
        for(ll x = i*i;x<n;x*=i){
            if(seen[x]) continue;
            seen[x] = true;
            ans++;
        }
    }
    cout << ans + 1 << endl;
    return 0;
}