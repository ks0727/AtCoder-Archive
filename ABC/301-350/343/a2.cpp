#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    string s;
    cin >> s;
    string ans = "";
    int cnt = 0;
    rep(i,s.size()){
        if(s[i] == '|') cnt++;
        if(cnt == 1 || s[i] == '|'){
            continue;
        }
        ans += s[i];
    }
    cout << ans << endl;
    return 0;
}