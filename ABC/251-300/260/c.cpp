#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main(){
    ll n,x,y;
    cin >> n >> x >> y;
    vector<ll> red(12),blue(12);
    red[1] = 0; blue[1] = 1;
    for(int i=2;i<=n;i++){
        blue[i] = red[i-1] + blue[i-1]*y;
        red[i] = red[i-1] + blue[i]*x;
    }
    cout << red[n] << endl; 
    return 0;
}