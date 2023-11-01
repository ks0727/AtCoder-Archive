#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    vector<string> s(8);
    string row = "87654321";
    string col = "abcdefgh";
    rep(i,8){
        cin >> s[i];
    }
    rep(i,8){
        rep(j,8){
            if(s[i][j] == '*'){
                cout << col[j] << row[i] << endl;
                return 0;
            } 
        }
    }
    return 0;
}
