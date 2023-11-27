#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main(){
    int n;
    cin >> n;
    vector<vector<ll> > d(n+1,vector<ll>(n+1));
    rep(i,n){
        for(int j = i+1;j<n;j++){
            ll dist;
            cin >> dist;
            d[i][j] = dist;
            d[j][i] = dist;
        }
    }
    if(n%2) n++;
    ll ans = 0;
    vector<bool> used(n);
    auto f = [&](auto f,ll w)->void{
        ans = max(ans,w);
        int mn = -1;
        for(int i = 0; i < n; i++){
            if(used[i]) continue; 
            mn = i;
            break;
        }
        if(mn == -1) return;
        used[mn] = true;
        for(int j = mn+1; j < (n);j++){
            if(used[j]) continue;
            used[j] = true;
            f(f,w+d[mn][j]);
            used[j] = false;
        }
        used[mn] =false;
    };
    f(f,0);
    cout << ans << endl;
    return 0;
}