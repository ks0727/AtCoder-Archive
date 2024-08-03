#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)

int main(){
    int n;
    cin >> n;
    map<string,int> mp;
    rep(i,n){
        string s;
        cin >> s;
        mp[s]++;
    }
    int m;
    cin >> m;
    rep(i,m){
        string t;
        cin >> t;
        if(mp.count(t)) mp[t]--;
    }
    int ans = 0;
    for(auto [s,cnt] : mp) ans = max(ans,cnt);
    cout << ans << endl;
}