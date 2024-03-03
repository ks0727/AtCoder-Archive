#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    string s = "atcoder";
    int l,r;
    cin >> l >> r;
    l--; r--;
    string ans = s.substr(l,r-l+1);
    cout << ans << endl;
    return 0;
}