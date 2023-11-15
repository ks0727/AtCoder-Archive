#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

struct Sieve{
    int n;
    vector<int> f,primes;
    Sieve(int n=1):n(n),f(n+1){
        f[0] = f[1] = -1;
        for(ll i = 2;i<=n;i++){
            if(f[i]) continue;
            primes.push_back(i);
            f[i] = i;
            for(ll j = i*i;j<=n;j+=i){
                if(!f[i]) f[j] = i;
            }
        }
    }
};

int main(){
    ll n;
    cin >> n;
    Sieve p(1e6);
    int m = p.primes.size();
    int ans = 0;
    rep(ai,m){
        ll a = p.primes[ai];
        if((ll)a*a*a*a*a > n) break;
        for(int bi = ai+1;bi<m;bi++){
            ll b = p.primes[bi];
            if((ll)a*a*b*b*b > n) break;
            for(int ci = bi+1;ci<m;ci++){
                ll c = p.primes[ci];
                if(a*a*b*c*c > n) break;
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}