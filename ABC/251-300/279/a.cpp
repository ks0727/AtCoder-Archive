#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int ans = 0;
    string s;
    cin >> s;
    rep(i,s.size()){
        if(s[i] == 'v') ans++;
        else ans += 2;
    }
    cout << ans << endl;
    return 0;
}