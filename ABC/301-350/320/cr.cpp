#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int m;
    cin >> m;
    string s0,s1,s2;
    cin >> s0 >> s1 >> s2;
    int ans = 500;
    rep(t0,300){
        rep(t1,300){
            rep(t2,300){
                if(t0 == t1) continue;
                if(t1 == t2) continue;
                if(t0 == t2) continue;
                if(!(s0[t0%m] == s1[t1%m])) continue;
                if(!(s1[t1%m] == s2[t2%m])) continue;
                ans = min(ans,max(max(t0,t1),t2));
            }
        }
    }
    if(ans == 500) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}