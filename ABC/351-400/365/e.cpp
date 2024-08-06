#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
using ll = long long;

int main(){
    int n;
    cin >> n;
    vector<ll> x;
    rep(i,n){
        ll a;
        cin >> a;
        vector<ll> old;
        swap(old,x);
        for(ll t : old){
            x.push_back(t);
            x.push_back(t^a);
        }
    }
    ll ans = 0;
    for(ll t : x) ans += t;
    cout << ans << endl;
    return 0;
}