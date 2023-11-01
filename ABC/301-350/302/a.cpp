#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;
int main(){
    ll a,b;
    cin >> a >> b;
    ll ans = 0;
    ans = (a-1)/b + 1;
    cout << ans << endl;
    return 0;
}