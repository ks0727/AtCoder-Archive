#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    int h = 8,w=8;
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    vector<bool> rows(h),cols(w);
    rep(i,h)rep(j,w){
        if(s[i][j] == '#'){
            rows[i] = true;
            cols[j] = true;
        }
    }
    int ans = 0;
    rep(i,h)rep(j,w){
        if(!rows[i] && !cols[j]) ans++;
    }
    cout << ans << endl;
    return 0;
}