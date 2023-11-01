#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    cin >> n;
    string s,t;
    cin >> s >> t;
    rep(i,n){
        if(s[i] == '1' && t[i] == 'l') continue;
        if(s[i] == 'l' && t[i] == '1') continue;
        if(s[i] == '0' && t[i] == 'o') continue;
        if(s[i] == 'o' && t[i] == '0') continue;
        if(s[i] != t[i]){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}