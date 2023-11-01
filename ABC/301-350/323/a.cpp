#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0;i<(n);i++)

int main(){
    string s;
    cin >> s;
    rep(i,s.size()){
        if(i == 0) continue;
        if(i%2 == 0) continue;
        if(s[i] == '1'){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}