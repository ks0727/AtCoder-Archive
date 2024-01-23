#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    string s;
    cin >> s;
    rep(i,101){
        rep(j,101){
            rep(k,101){
                string a = string(i,'A');
                string b = string(j,'B');
                string c = string(k,'C');
                if(a+b+c == s){
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "No" << endl;
    return 0;
}