#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using ull = unsigned long long;

int main(){
    const int M = 1e6+1;
    ull n;
    cin >> n;
    vector<bool> isprime(M,true);
    isprime[0] = false;
    isprime[1] = false;
    for(ull i=2;i<M;i++){
        if(!isprime[i]) continue;
        isprime[i] = true;
        for(ull j = i*2;j<=M; j+=i){
            isprime[j] = false;
        }
    }
    vector<ull> ps;
    rep(i,M) if(isprime[i]) ps.push_back(i);
    int r = ps.size()-1;
    ull ans = 0;
    rep(l,ps.size()){
        while(r >= 0 && ps[l]*ps[r]*ps[r]*ps[r] > n) r--;
        if(r <= l) break;
        ans += r-l;
    }
    cout << ans << endl;
    return 0;
}