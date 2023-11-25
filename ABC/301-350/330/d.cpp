#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;
int main(){
    int n;
    cin >> n;
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    vector<int> row(n),col(n);
    rep(i,n){
        rep(j,n){
            if(s[i][j] != 'o') continue;
            row[i]++;
            col[j]++;
        }
    }  
    ll ans = 0;
    rep(i,n){
        rep(j,n){
            if(s[i][j] != 'o') continue;
            ans += (ll)(row[i]-1)*(col[j]-1);
        }
    }
    cout << ans << endl;
    return 0;  
}