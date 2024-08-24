#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    int l,r;
    cin >> l >> r;
    const int M = 1e6;
    vector<bool> prime(M+1,true);
    prime[0] = prime[1] = false;
    vector<bool> pfp(M,false);
    for(int i=2;i<=M;i++){
        if(!prime[i]) continue;
        for(int j=i*2;j<=M;j+=i) prime[j] = false;
    }
}
