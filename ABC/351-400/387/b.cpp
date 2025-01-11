#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    int x;
    cin >> x;
    long long ans = 0;
    rep(i,10)rep(j,10){
        if(i*j != x) ans += i*j;
    }
    cout << ans << endl;
    return 0;
}