#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main(){
    ll n;
    cin >> n;
    vector<int> a;
    rep(i,60){
        if(n & (1<<i)) a.push_back(i);
    }
    int k = a.size();
    vector<ll> res;
    rep(i,i<(1<<k)){
        ll cur = 0;
        rep(j,k){
            if(i & (1<<j)) cur |= (1<<a[j]); //curは, ?00???0みたいなのがあった時に, ある桁のbitを立てた数
        }
        res.push_back(cur);
    }
    sort(res.begin(),res.end());
    for(ll x : res) cout << x << endl;
    return 0;
}