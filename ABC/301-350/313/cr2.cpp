#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main(){
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll all = 0;
    rep(i,n){
        cin >> a[i];
        all += a[i];
    }
    ll ave = all / n;
    ll rest = all % n;
    sort(a.begin(),a.end());
    vector<ll> result(n,ave);
    for(int i = n-rest;i<n;i++){
        result[i] = ave+1;
    }
    ll ans = 0;
    rep(i,n){
        if(result[i] - a[i] > 0){
            ans += result[i] - a[i];
        }
    }
    cout << ans << endl;
    return 0;
}