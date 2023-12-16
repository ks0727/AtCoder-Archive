#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    char c;
    cin >> c;
    int num = c - '0';
    string ans = "";
    rep(i,num) ans += c;
    cout << ans << endl;
    return 0;
}