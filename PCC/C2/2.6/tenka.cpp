#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    int n;
    cin >> n;
    vector<bool> prime(n,true);
    prime[0] = false; prime[1] = false;
    for(int i=2;i<n;++i){
        if(!prime[i]) continue;
        for(int j = i*2;j<n;j+=i){
            prime[j] = false;
        }
    }
    int ans = 0;
    rep(i,n) if(prime[i]) ans++;
    cout << ans << '\n';
    return 0;
}