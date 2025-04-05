#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    int n;
    cin >> n;
    string s,t;
    cin >> s >> t;
    int ans = 0;
    for(int i=0;i<n;i++) if(s[i] != t[i]) ans++;
    cout << ans << endl;
    return 0;
}