#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

bool isprime(int N) {
    if (N < 2) return false;
    for (long long i = 2; i * i <= N; ++i) {
        if (N % i == 0) return false;
    }
    return true;
}

int main(){
    ll n;
    cin >> n;
    vector<ll> prime;
    rep(i,5000){
        if(isprime(i+1)) prime.emplace_back(i+1);
    }
    int size = prime.size();
    int ans = 0;
    rep(i,size){
        rep(j,size){
            rep(k,size){
                if(i < j && j < k){
                    ll num = prime[i]*prime[j]*prime[k];
                    if(num <= sqrt(n * prime[j])){
                        ans++;
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}