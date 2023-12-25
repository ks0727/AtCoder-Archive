#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main(){
    int n;
    cin >> n;
    vector<ll> arr;
    ll x = 0;
    rep(i,13){
        x = x*10 +1;
        arr.push_back(x);
    }
    vector<ll> ru;
    for(ll a : arr){
        for(ll b : arr){
            for(ll c : arr){
                ru.push_back(a+b+c);
            }
        }
    }
    sort(ru.begin(),ru.end());
    ru.erase(unique(ru.begin(),ru.end()),ru.end());
    cout << ru[n-1] << endl;
    return 0;
}