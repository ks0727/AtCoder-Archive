#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    string s;
    cin >> s;
    bool ans = true;
    if(s[0] != '<') ans = false;
    if(s.back() != '>') ans = false;
    for(int i = 1;i<s.size()-1;i++){
        if(s[i] != '=') ans = false;
    }
    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}