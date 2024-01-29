#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    string s;
    cin >> s;
    bool ans = true;
    if(s.front() < 'A' || s.front() > 'Z') ans = false;
    for(int i=1;i<s.size();i++){
        if(s[i] < 'a' || s[i] > 'z') ans = false;
    }
    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}