#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int kanma = 0;
    rep(i,n){
        if(s[i] == '"') kanma++;
        if(kanma%2 == 0 && s[i] == ',') s[i] = '.';
    }
    cout << s << endl;
    return 0;
}