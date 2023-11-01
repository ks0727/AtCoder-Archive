#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    string ans;
    for(char c: s){
        if(c=='a') continue;
        if(c=='i') continue;
        if(c=='u') continue;
        if(c=='e') continue;
        if(c=='o') continue;
        ans += c;
    }
    cout << ans << endl;
    return 0;
}