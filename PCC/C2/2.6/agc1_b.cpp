#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using ll = long long;

int main(){
    int n,x;
    cin >> n >> x;
    ll ans = 0; 
    auto f = [&](auto f, int a, int b)-> void{
        if(a < b) swap(a,b);
        if(b == 1) return;
        ans += (ll)(a / b) * b;
        f(f,a,gcd(a,b));
    };
    f(f,n,n-x);
    cout << ans << endl;
    return 0;
}