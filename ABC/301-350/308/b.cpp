#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n,m;
    cin >> n >> m;
    map<string,int> mp;
    vector<string> ate(n);
    rep(i,n) cin >> ate[i];
    vector<string> d(m);
    rep(i,m) cin >> d[i];
    vector<int> prices(m+1);
    rep(i,m+1) cin >> prices[i];
    rep(i,m){
        mp[d[i]] = prices[i+1];
    }
    int ans = 0;
    rep(i,n){
        if(mp.count(ate[i])){
            ans += mp[ate[i]];
        }else{
            ans += prices[0];
        }
    }
    cout << ans << endl;
    return 0;
}