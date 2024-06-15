#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n,m;
    cin >> n >> m;
    vector<string> s(n);
    rep(i,n) cin >> s[i];

    int n2 = 1<<n;
    int ans = 1000;
    rep(bit,n2){
        vector<bool> sell(m);
        int shop = 0;
        rep(i,n){
            if(bit&(1<<i)){
                shop++;
                rep(j,m){
                    if(s[i][j] == 'o') sell[j] = true;
                }
            }
        }
        bool ok = true;
        rep(j,m) if(!sell[j]) ok = false;
        if(ok) ans = min(ans,shop);
    }
    cout << ans << endl;
    return 0;
}