#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0;i<(n);i++)
using ll = long long;

int main(){
    int n;
    cin >> n;
    map<ll,ll> mp;
    rep(i,n){
        int s,c;
        cin >> s >> c;
        mp[s] = c;
    }
    int ans = 0;
    while(mp.size()){
        auto [s,c] = *mp.begin();
        mp.erase(mp.begin());
        ans += c%2;
        c /= 2;
        if(c) mp[s*2] += c;
    }
    cout << ans << endl;
    return 0;
}