#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;
int main(){
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<int> balls;
    rep(i,n){
        balls.push_back(a[i]);
        while(1){
            int sz = balls.size();
            if(sz <= 1) break;
            if(balls[sz-1] != balls[sz-2]) break;
            ll x = balls[sz-1]; 
            balls.pop_back();
            balls.pop_back();
            balls.push_back(x+1);
        }
    }
    cout << balls.size() << endl;
    return 0;
}