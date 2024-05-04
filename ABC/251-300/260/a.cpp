#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    string s;
    cin >> s;
    if(s[0] != s[1] && s[0] != s[2]){
        cout << s[0] << endl;
    }else if(s[1] != s[0] && s[1] != s[2]){
        cout << s[1] << endl;
    }else if(s[2] != s[0] && s[2] != s[1]){
        cout << s[2] << endl;
    }else{
        cout << -1 << endl;
    }
    return 0;
}