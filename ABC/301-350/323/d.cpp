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
        mp[s] += c;
    }
    for(auto [size,cnt] : mp){
        if(mp[size] >= 2){
            if(mp[size] % 2 == 0){
                mp[2*size] += mp[size]/2;
                mp[size] = 0;
            }else{
                mp[2*size] += (mp[size]-1)/2;
                mp[size] = 1;
            }
        }
    }
    ll ans = 0;
    for(auto [size,cnt] : mp){
        if(cnt <= 0) continue;
        ans++;
    }
    cout << ans << endl;
}