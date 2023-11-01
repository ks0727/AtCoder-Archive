#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n,m;
    cin >> n >> m;
    vector<string> s(n),t(m);
    rep(i,n) cin >> s[i];
    rep(i,m) cin >> t[i];
    int ans = 0;
    rep(i,n){
        string last_s = s[i].substr(s[i].size()-3,3);
        rep(j,m){
            if(last_s == t[j]){
                ans++;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}