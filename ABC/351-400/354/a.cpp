#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

ll pow(ll a, ll b){
    ll res = 1;
    rep(i,b) res *= a;
    return res;
}

int main(){
    ll h;
    cin >> h;
    ll i = 0;
    ll now = 0;
    while(1){
        ll x = pow(2,i);
        now += x;
        if(now > h) break;
        i++;
    }
    cout << i+1 << endl;
    return 0;
}