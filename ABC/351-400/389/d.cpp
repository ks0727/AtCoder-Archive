#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    long long R;
    cin >> R;
    long long ans = 0;
    for(long long i=1;i<=R;i++){
        long long r=R,l=0;
        while(r-l>1){
            long long mid = (r+l)/2;
            long long res = R*R - i*i - i;
            if(2*mid*mid+2*mid <= 2*res-1) l = mid;
            else r = mid;
        }
        ans += l;
    }
    ans *= 4;
    ans += 4*(R-1) + 1;
    cout << ans << endl;
    return 0;
}