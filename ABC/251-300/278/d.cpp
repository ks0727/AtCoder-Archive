#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main(){
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    int q;
    cin >> q;
    ll now = -1;
    map<int,ll> mp;
    rep(qi,q){
        int type;
        cin >> type;
        if(type == 1){
            ll x;
            cin >> x;
            now = x;
            mp.clear();
        }
        if(type == 2){
            int i; ll x;
            cin >> i >> x;
            i--;
            if(now != -1) mp[i] += x;
            else a[i] += x;
        }
        if(type == 3){
            int i;
            cin >> i;
            i--;
            if(now != -1) cout << now + mp[i] << '\n';
            else cout << a[i] << '\n';
        }
    }
    return 0;
}