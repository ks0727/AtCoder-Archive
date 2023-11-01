#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    string s;
    cin >> s;
    rep(i,s.size()){
        if(s[i] >= 'A' && s[i] <= 'Z'){
            cout << i+1 << endl;
            return 0;
        }
    }
    return 0;
}