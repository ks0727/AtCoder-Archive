#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using ll = long long;

int main(){
    int n;
    cin >> n;
    vector<ll> h(n);
    rep(i,n) cin >> h[i];
    ll t = 0;
    rep(i,n){
        if(t%3 == 1){
            h[i] -= 1; t++;
            if(h[i] <= 0) continue;
            h[i] -= 3; t++;
            if(h[i] <= 0) continue; 
        }else if(t%3 == 2){
            h[i] -= 3; t++;
            if(h[i] <= 0) continue;
        }
        
        ll num = h[i]/5;
        t += num*3;
        h[i] -= num*5;
        if(h[i] <= 0) continue;
        else if(h[i] == 1) t++;
        else if(h[i] == 2) t+=2;
        else t+=3;
    }
    cout << t << endl;
    return 0;
}