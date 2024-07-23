#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using ll = long long;

int main(){
    ll n;
    cin >> n;
    const int M = 38;
    vector<ll> arr(M);
    vector<ll> s(M+1);
    arr[0] = 10;
    arr[1] = 9;
    rep(i,M){
        if(i <= 1) continue;
        arr[i] = 9 * arr[i-2];
    }   
    rep(i,M+1) s[i+1] = s[i]+arr[i];

}