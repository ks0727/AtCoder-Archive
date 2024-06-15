#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;
int main(){
    ll n,a;
    cin >> n >> a;
    vector<ll> t(n);
    rep(i,n) cin >> t[i];
    ll prev = 0;
    rep(i,n){
        if(i == 0){
            cout << t[i]+a << endl;
            prev = t[i]+a;
        } 
        else{
            if(prev <= t[i]){
                cout << t[i] + a << endl;
                prev = t[i]+a;
            }else{
                cout << prev + a << endl;
                prev += a;
            }
        }
    }
    return 0;
}