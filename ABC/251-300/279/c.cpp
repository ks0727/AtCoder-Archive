#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

map<string,int> dist(vector<string> x,int h, int w){
    map<string,int> ret;
    rep(i,w){
        string nx = "";
        rep(j,h){
            nx += x[j][i];
        }
        ret[nx]++;
    }
    return ret;
}

int main(){
    int h,w;
    cin >> h >> w;
    vector<string> s(h),t(h);
    rep(i,h) cin >> s[i];
    rep(i,h) cin >> t[i];
    map<string,int> dist_s,dist_t;
    dist_s = dist(s,h,w);
    dist_t = dist(t,h,w);
    bool ans = true;
    for(auto [col,cnt] : dist_s){
        if(!dist_t.count(col)) ans = false;
        else{
            if(cnt != dist_t[col]) ans = false;
        }
    }
    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}