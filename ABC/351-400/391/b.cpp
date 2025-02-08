#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    int n,m;
    cin >> n >> m;
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    vector<string> t(m);
    rep(i,m) cin >> t[i];
    rep(i,n-m+1){
        rep(j,n-m+1){
            bool ok = true;
            rep(ii,m){
                if(!ok) break;
                rep(jj,m){
                    if(s[i+ii][j+jj] != t[ii][jj]){
                        ok = false;
                        break;
                    }
                }
            }
            if(ok) {
                cout << i+1 << ' ' << j+1 << endl;
                return 0;
            }
        }
    }
    return 0;
}