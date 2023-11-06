#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main(){
    int t;
    cin >> t;
    auto gcd = [&](auto gcd,int a, int b)->int{
        if(a % b == 0) return b;
        else return gcd(gcd,b,a%b);
    };
    auto lcm = [&](auto lcm,int a, int b) -> ll{
        return (ll)a*b/gcd(gcd,a,b);
    };
    rep(i,t){
        int n,d,k;
        cin >> n >> d >> k;
        if(k == 1){
            cout << 0 << endl;
        }else{
            ll l = lcm(lcm,n,d);
            int mul = l/d;
            int key = k - 1;
            int add = key / mul;
            ll ans = (ll)key * d;
            ans %= n;
            ans += add;
            cout << ans << endl;
        }
    }
    return 0;
}