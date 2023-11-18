#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    string s;
    cin >> s;
    int n = s.size();
    rep(i,n){
        cout << s[i] << ' ';
    }
    return 0;
}