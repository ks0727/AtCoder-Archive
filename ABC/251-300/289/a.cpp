#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    string s;
    cin >> s;
    string ans = "";
    rep(i,s.size()){
        if(s[i] == '0'){
            ans+='1';
        } 
        if(s[i] == '1') ans+='0';
    }
    cout << ans <<  endl;
    return 0;
}