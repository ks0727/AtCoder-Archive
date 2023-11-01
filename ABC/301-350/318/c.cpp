#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;
int main(){
    ll n,d,p;
    cin >> n >> d >> p;
    vector<ll> f(n);
    rep(i,n) cin >> f[i];
    float oneprice = p/d;
    sort(f.rbegin(),f.rend());
    ll sum = 0;
    rep(i,n) sum += f[i];
    
    if(n < d && sum > p){
        cout << p << endl;
        return 0;
    }
    ll index = 0;
    if(n % d == 0) index = n/d;
    if(n % d != 0) index = n/d + 1;
    if(index*p < sum){
        cout << index * p << endl;
        return 0;
    }
    ll replace = 0;
    rep(i,n){
        if(f[i] >= oneprice) replace++;
    }
    ll sets = replace / d;
    rep(i,sets*d){
        f[i] = 0;
    }
    ll ans = 0;
    rep(i,n){
        ans += f[i];
    }
    ans += p * sets;
    cout << ans << endl;
    return 0;
}