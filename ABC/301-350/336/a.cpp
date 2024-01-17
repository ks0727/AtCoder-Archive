#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    cin >> n;
    string ans = "L";
    rep(i,n) ans += 'o';
    ans += "ng";
    cout << ans << endl;
    return 0;
}