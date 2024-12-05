#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    int n,d;
    cin >> n >> d;
    string s; cin >> s;
    rep(i,n){
        if(s[i] == '@' && d > 0) {
            s[i] = '.';
            d--;
        }
    }
    int ans = 0;
    rep(i,n) if(s[i] == '.') ans++;
    cout << ans << endl;
    return 0;
}