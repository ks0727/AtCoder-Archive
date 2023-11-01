#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;
int main(){
    int n;
    cin >> n;
    vector<ll> x(n),y(n);
    vector<pair<int,int> > z(n);
    rep(i,n) cin >> x[i] >> y[i] >> z[i].first;
    rep(i,n){
        if(x[i] > y[i]) z[i].second = 0;
        else z[i].second = 1;
    }
    int all;
    rep(i,n) all += z[i].first;
    int takahashi,aoki;
    rep(i,n){
        if(z[i].second == 0) takahashi += z[i].first;
        else aoki += z[i].first;
    }
    int rest = int(all/2 - takahashi);
    int ans;
    if(rest < 0){
        ans = 0;
    } 
    else{
        while(rest > 0){
            
        }
    }
}