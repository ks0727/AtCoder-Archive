#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using ll = long long;
int main(){
    int q;
    cin >> q;
    map<ll,int> mp;
    rep(qi,q){
        int type;
        cin >> type;
        if(type == 1){
            mp[0]++;
        }else if(type == 2){
            ll t;
            cin >> t;
            map<ll,int> old;
            swap(old,mp);
            for(auto [val,cnt] : old){
                mp[val-t] = cnt;
            }
        }else if(type == 3){
            ll h;
            cin >> h;
            set<ll> erase;
            int ans = 0;
            for(auto [val,cnt] : mp){
                if(-val < h) break;
                ans+=cnt;
                erase.insert(val);
            }
            for(ll x : erase){
                mp.erase(x);
            }
            cout << ans << '\n';
        }
    }
    return 0;
}