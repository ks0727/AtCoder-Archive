#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    string s;
    cin >> n;
    cin >> s;
    bool ans = true;
    rep(i,n){
        if(s[i] == s[i+1]){
            ans = false;
        }
    }
    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}