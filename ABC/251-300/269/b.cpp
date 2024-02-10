#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    vector<string> s(10);
    rep(i,10) cin >> s[i];
    int a,b,c,d;
    bool done = false;
    rep(i,10){
        if(done) break;
        rep(j,10){
            if(s[i][j] == '#'){
                a = i+1;
                c = j+1;
                done= true;
                break;
            }
        }
    }
    for(int j = c-1;j<10;j++){
        if(s[a-1][j] != '#'){
                d = j;
                break;
        }
        if(j == 9) d = 10;
    }
    for(int i=a-1;i<10;i++){
        if(s[i][c-1] != '#'){
            b = i;
            break;
        }
        if(i == 9) b = 10;
    }
    cout << a << ' ' << b << endl;
    cout << c << ' ' << d << endl;
    return 0;
}