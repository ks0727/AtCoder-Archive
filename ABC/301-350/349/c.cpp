#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)

int main(){
    string s,t;
    cin >> s >> t;
    int need = 3;
    if(t[2] == 'X') need--;
    for(char &c: t) c+=32;
    int now = 0;
    rep(i,s.size()){
        if(s[i] == t[now]){
            now++;
            if(now == need) break;
        }
    }
    if(now == need) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}