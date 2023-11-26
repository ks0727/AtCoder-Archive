#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main(){
    ll d;
    cin >> d;
    ll ans = d;
    ll y = 2e6;
    for(ll x = 0;x<=2e6;x++){
        while(x*x+y*y > d && y > 0){
            y--;
        }
        ans = min(ans,abs(x*x+y*y-d));
        ans = min(ans,abs(x*x+(y+1)*(y+1) - d));
    }   
    cout << ans << endl;
}