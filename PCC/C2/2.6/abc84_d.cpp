#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    int N = 100000;
    vector<bool> prime(N+1,true);
    prime[0] = false; prime[1] = false;
    for(int i=2;i<=N;++i){
        if(!prime[i]) continue;
        for(int j = i*2;j<=N;j+=i){
            prime[j] = false;
        }
    }
    vector<bool> ok(N+1,false);
    rep(i,N+1){
        if(!prime[i]) continue;
        if(!prime[(i+1)/2]) continue;
        ok[i] = true;
    }
    vector<int> s(N+2);
    rep(i,N+1) s[i+1] = s[i] + (ok[i] ? 1 : 0);
    int q;
    cin >> q;
    while(q--){
        int l,r;
        cin >> l >> r; r++;
        cout << s[r] - s[l] << '\n';
    }
    return 0;
}