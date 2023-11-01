#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    string s;
    cin >> s;
    int b1 = -1,b2 = -1,r1 = -1,r2=-1,k=-1;
    rep(i,8){
        if(b1 == -1 && s[i] == 'B') b1 = i;
        if(b1 != -1 && s[i] == 'B') b2 = i;
        if(s[i] == 'K') k = i;
        if(r1 == -1 && s[i] == 'R') r1 = i;
        if(r1 != -1 && s[i] == 'R') r2 = i;
    }
    int ans = false;
    if((b1+b2) % 2 == 1 && r1 < k && k < r2) ans = true;
    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}