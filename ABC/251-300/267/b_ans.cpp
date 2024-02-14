#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    string s;
    cin >> s;
    string c = "x";
    if(s[6] == '1') c += 'o'; else c += 'x';
    if(s[3] == '1') c += 'o'; else c += 'x';
    if(s[1] == '1' || s[7] == '1') c += 'o'; else c += 'x';
    if(s[0] == '1' || s[4] == '1') c += 'o'; else c += 'x';
    if(s[2] == '1' || s[8] == '1') c += 'o'; else c += 'x';
    if(s[5] == '1') c += 'o'; else c += 'x';
    if(s[9] == '1') c += 'o'; else c += 'x';
    int xo = 0;
    for(int i=0;i+1<c.size();i++){
        if(c[i] == 'x' && c[i+1] == 'o') xo++;
    }
    if(xo > 1 && s[0] == '0') cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}