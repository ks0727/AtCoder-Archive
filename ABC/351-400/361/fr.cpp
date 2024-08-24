#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using ll = long long;

int main(){
    ll n;
    cin >> n;
    ll ans = 0;
    const int M = 1e8;
    vector<bool> prime(M,true);
    for(int i=2;(ll)i<=M;i++){
        if(!prime[i]) continue;
        for(int j=i*2;(ll)j<=n;j+=i) prime[j] = false; 
    }
    for(int i=2;(ll)i<=n;++i){
        if(!prime[i]) continue;
        for(int j=i*2;(ll)j<=n;j*=i) ans++;
    }
    cout << ans+1 << endl;
    return 0;
}