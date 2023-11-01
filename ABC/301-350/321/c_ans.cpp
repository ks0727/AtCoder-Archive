#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;
int main(){
    int k;
    cin >> k;
    vector<ll> a;
    rep(s,1<<10){ //2^10-1まで繰り返す
        ll x = 0;
        for(int i = 9;i>= 0;i--){
            if(s>>i&1){
                x = x * 10 + i;
            }
        }
        if(x == 0) continue;
        a.push_back(x);
    }
    sort(a.begin(),a.end());
    cout << a[k-1] << endl;
}