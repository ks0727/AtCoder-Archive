#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using ll = long long;

const ll mod = 1e16+61;

int main(){
    int n;
    cin >> n;
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    const int M = 200;
    map<ll,int> mp;

    rep(i,n){
        ll x = 0;
        rep(j,s[i].size()){
            x *= M;
            x %= mod;
            x += s[i][j];
            x %= mod;
            mp[x]++;
        }
    }

    ll ans = 0;
    for(auto [val,cnt] : mp){
        ans += (ll)cnt*(cnt-1)/2;
    }
    cout <<ans << endl;
}
