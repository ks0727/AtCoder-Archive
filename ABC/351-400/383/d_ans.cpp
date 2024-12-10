#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using ll = long long;
int main(){
    ll n;
    cin >> n;
    const int M = 2e6 + 5;
    vector<bool> isp(M,true);
    isp[0] = isp[1] = false;
    rep(i,M){
        if(!isp[i]) continue;
        for(int j=i;j<=M;j+=i) isp[j] = false;
    }
    vector<ll> primes;
    rep(i,M) if(isp[i]) primes.push_back(i);
    ll ans = 0;
    for(ll p1 : primes){
        for(ll p2 : primes){
            if(p2 >= p1) continue;
            if(p1*p1*p2*p2 > n) continue;
            ans++;
        }
    }
    for(ll p : primes){
        ll x = 1;
        rep(i,8) x *= p;
        if(x > n) break;
        ans++;
    }
    cout << ans << endl;
    return 0;
}