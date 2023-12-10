#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;
int main(){
    ll n,s,k;
    cin >> n >> s >> k;
    vector<ll> p(n),q(n);
    rep(i,n) cin >> p[i] >> q[i];
    ll sum = 0;
    rep(i,n){
        sum += p[i]*q[i];
    }
    if(sum >= s){
        cout << sum << endl;
        return 0; 
    }else{
        cout << sum + k << endl;
        return 0;
    }
    return 0;
}