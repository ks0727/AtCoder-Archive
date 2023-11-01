#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;
int main(){
    int n;
    cin >> n;
    vector<vector<int> > d(n+1,vector<int>(n+1));
    rep(i,n){
        for(int j = i+1;j<n;j++){
            cin >> d[i][j];
            d[j][i] = d[i][j];
        }
    }
    if(n%2 == 1) n++;
    
    ll ans = 0;
    vector<bool> used(n);
    auto f = [&](auto f,ll w) -> void{
        ans = max(ans,w);
        int i = 0;
        while (i < n && used[i]) i++;
        if(i == n) return;
        used[i] = true;
        for(int j = i+1;j<n;j++){
            if(used[j]) continue;
            f(f,w+d[i][j]);
            used[j] = false;
        }
        used[i] = false;
    };
    f(f,0);
    cout << ans << endl;
    return 0;
}