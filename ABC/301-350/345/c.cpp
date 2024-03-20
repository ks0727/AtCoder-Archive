#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

ll c2(ll x){
    return x*(x-1)/2;
};

int main(){
    string s;
    cin >> s;
    ll n = s.size();
    vector<ll> cnt(26);
    rep(i,n){
        cnt[s[i]-'a']++;
    }
    ll ans = c2(n);
    bool sub = false;
    rep(i,26){
        ll minus = c2(cnt[i]);
        if(minus != 0) sub = true;
        ans -= minus;
    }
    if(sub) ans++;
    cout << ans << endl;
    return 0;
}