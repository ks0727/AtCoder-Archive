#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)

int main(){
    int h,w,k;
    cin >> h >> w >> k;
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    const int INF = 1001001001;
    auto f = [&](string &ns){
        int n = ns.size();
        int res = INF;
        vector<int> cnt(3);
        rep(i,k){
            if(ns[i] == 'o') cnt[0]++;
            else if(ns[i] == '.') cnt[1]++;
            else if(ns[i] == 'x') cnt[2]++;
        }
        if(cnt[2] == 0) res = min(res,cnt[1]);
        for(int i=k;i<n;i++){
            if(ns[i-k] == 'o') cnt[0]--;
            else if(ns[i-k] == '.') cnt[1]--;
            else if(ns[i-k] == 'x') cnt[2]--;
            if(ns[i] == 'o') cnt[0]++;
            else if(ns[i] == '.') cnt[1]++;
            else if(ns[i] == 'x') cnt[2]++;
            if(cnt[2] == 0) res = min(res,cnt[1]);
        }
        return res;
    };
    int ans = INF;
    if(w >= k) rep(i,h) ans = min(ans,f(s[i]));
    vector<string> s2(w,string(h,'.'));
    rep(i,h)rep(j,w) s2[j][i] = s[i][j];
    if(h >= k) rep(i,w) ans = min(ans,f(s2[i]));
    if(ans != INF) cout << ans << endl;
    else cout << -1 << endl;
    return 0;
}