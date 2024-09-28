#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    string s;
    cin >> s;
    int ans = 0;
    int now = 0;
    rep(i,26) if(s[i] == 'A') now = i;
    rep(i,25){
        rep(j,26){
            if(s[j] == 'A'+i+1){
                ans += abs(now-j);
                now = j;
            }
        }
    }
    cout << ans << endl;
    return 0;
}