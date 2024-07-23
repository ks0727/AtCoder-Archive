#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    int n,t,p;
    cin >> n >> t >> p;
    vector<int> l(n);
    rep(i,n) cin >> l[i];
    int ans = 0;
    int ok = 0;
    vector<bool> done(n);
    while(1){
        rep(i,n){
            if(done[i]) continue;
            l[i]++;
            if(l[i] >= t){
                ok++;
                done[i] = true;
            }
            if(ok >= p){
                if(ans == 0) cout << 0 << endl;
                else cout << ans+1 << endl;
                return 0;
            }
        }
        ans++;
    }
    return 0;
}