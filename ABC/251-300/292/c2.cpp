#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main(){
    int n;
    cin >> n;
    map<int,ll> mp;
    for(int a = 1;a<=n;a++){
        for(int b=1;b<=n/a;b++){
            mp[a*b]++;
        }
    }
    ll ans = 0;
    for(int x=1;x<n;x++){
        ans += mp[x]*mp[n-x];
    }
    cout << ans << endl;
    return 0;
}