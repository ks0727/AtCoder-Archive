#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    long long R;
    cin >> R;
    long long y = R;
    long long ans = 0;
    for(long long x = 1;x<R;x++){
        auto f = [&](long long i){
            long long res = 2*R*R - 2*i*i - 2*i - 1;
            return res;
        };
        while(y > 0 && f(x) < 2*y*y+2*y) y--;
        ans += y;
    }
    ans *= 4;
    ans += 4*(R-1) + 1;
    cout << ans << endl;
    return 0;
}