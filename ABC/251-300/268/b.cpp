#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    string s,t;
    cin >> s >> t;
    int n = s.size();
    bool ans = true;
    if(s.size() > t.size()){
        ans = false;
    }
    if(t.substr(0,n) != s) ans = false;
    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}