#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    bool good = false;
    rep(i,n){
        if(s[i] == 'x'){
            cout << "No" << endl;
            return 0;
        }
        if(s[i] == 'o'){
            good = true;
        }
    }
    if(good) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}