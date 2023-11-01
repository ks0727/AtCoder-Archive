#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main(){
    ll a,b;
    cin >> a >> b;
    ll ans = 0;
    auto sub = [&](auto sub, ll a, ll b)->void{
        ll s = a/b;
        ans += s;
        a%=b;
        if(a == b || a == 0) return;
        if(a < b) sub(sub,b,a);
        else sub(sub,a,b);
    };
    if(a == b){
        cout << 0 << endl;
        return 0;
    } 
    else{
        if(a > b) sub(sub,a,b);
        else sub(sub,b,a);
    }
    cout << ans - 1 << endl;
    return 0;
}