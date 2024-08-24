#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using ll = long long;
int main(){
    int t;
    cin >> t;
    const int M = 1e6;
    vector<bool> isPrime(M+1,true);
    isPrime[0] = false; isPrime[1] = false;
    vector<int> ps;
    for(int i=2;i<=M;i++){
        if(!isPrime[i]) continue;
        ps.push_back(i);
        for(int j=i*2;j<=M;j+=i) isPrime[j] = false;
    }
    auto p = [&](int n){
        int res = 0;
        for(int i=2;i*i<=n;i++){
            if(!isPrime[i]) continue;
            if(n%i != 0) continue;
            res++;
            if(isPrime[n%i] && i != n%i) res++;
        }
        return res;
    };
    map<int,ll> mp;
    mp[1] = 2;
    auto f = [&](auto f, int x)->ll{
        if(mp.count(x)) return mp[x];
        if(isPrime[x]) return mp[x] = x-1 + f(f,x-1);
        ll k = upper_bound(ps.begin(),ps.end(),x) - ps.begin();
        mp[x] = f(f,x-1) + k + 1 - p(x);
        return mp[x];
    };
    while(t--){
        int x;
        cin >> x;
        ll ans = f(f,x);
        cout << ans << "\n";
    }
}