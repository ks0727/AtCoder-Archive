#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;
ll c2(int val){
    return (ll)val*(val-1)/2;
}

int main(){
    int n; cin >> n;
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    map<string,int> mp;
    rep(i,n){
        string t = "";
        rep(j,s[i].size()){
            t += s[i][j];
            mp[t]++;
        }
    }
    ll ans = 0;
    for(auto[str,val] : mp){
        ans += c2(val);
    }
    cout << ans << endl;
    return 0;
}