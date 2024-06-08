#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

char toUpper(char c) {
    return ('a' <= c && c <= 'z') ? ('A' + c - 'a') : c;
}

char toLower(char c) {
    return ('A' <= c && c <= 'Z') ? ('a' + c - 'A') : c;
}
int main(){
    string s;
    cin >> s;
    int l = 0,u = 0;
    rep(i,s.size()){
        if(isupper(s[i])) u++;
        else l++;
    }
    if(u > l){
        rep(i,s.size()) s[i] = toUpper(s[i]);
    }else{
        rep(i,s.size()) s[i] = toLower(s[i]);
    }
    cout << s << endl;
    return 0; 
}