#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n,m;
    cin >> n >> m;
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    int ans = 0;
    rep(i,n){
        for(int j=i;j<(n);j++){
            if(i == j) continue;
            rep(k,m){
                if(s[i][k] == 'x' && s[j][k] == 'x') break;
                if(k == m-1) ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}