#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main(){
    int n;
    cin >> n;
    vector<ll> repunits;
    for(ll a=1;a<1e12;a=a*10+1){
        repunits.push_back(a);
    }
    set<ll> s;
    for(ll a : repunits){
        for(ll b : repunits){
            for(ll c : repunits){
                s.insert(a+b+c);
            }
        }
    }
    vector<ll> d;
    for(ll x:s) d.push_back(x);
    cout << d[n-1] << endl;
    return 0;
}