#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using ll = long long;

int main(){
    int n;
    cin >> n;
    ll now = 1;
    rep(i,n){
        ll t;
        cin >> t;
        now = lcm(now,t);
    }
    cout << now << endl;
    return 0;
}