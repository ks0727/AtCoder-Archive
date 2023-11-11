#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;
using P = pair<ll,ll>;
int main(){
    int n;
    cin >> n;
    map<ll,ll> mp;
    rep(i,n){
        ll s,c;
        cin >> s >> c;
        mp[s] += c;
    }
    int ans = 0;
    for(auto[s,c]:mp){
        if(c > 1) mp[s*2]+=(c/2);
        if(c&1) ans++; //cが奇数であれば
    }
    cout << ans << endl;
    return 0;
}