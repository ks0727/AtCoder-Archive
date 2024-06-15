#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    string s,t;
    cin >> s >> t;
    bool ans = false;
    if(s == "AtCoder" && t == "Land") ans = true;
    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}