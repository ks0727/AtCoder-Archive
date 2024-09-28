#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    string s;
    cin >> s;
    string ans  = "";
    rep(i,s.size()) if(s[i] != '.') ans += s[i];
    cout << ans << endl;
    return 0;
}