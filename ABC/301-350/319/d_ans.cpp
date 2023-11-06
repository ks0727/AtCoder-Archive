#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i =0;i<(n);i++)
using ll = long long;

int main(){
    int n,m;
    cin >> n >> m;
    vector<ll> l(n);
    rep(i,n) cin >> l[i];
    ll left = 0, right = 1e15;
    while(right-left >1 ){
        ll key = (left+right)/2;
        auto f = [&](ll w){
            int line =0;
            ll rem =0;
            rep(i,n){
                if(rem >= l[i]+1){
                    rem -= l[i] + 1;
                }else{
                    line++;
                    rem = w - l[i];
                    if(rem < 0) return false;
                }
            }
            return line <= m;
        };
        if(f(key)) right = key;
        else left = key;
    }
    cout << left << endl;
}