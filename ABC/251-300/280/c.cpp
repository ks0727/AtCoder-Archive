#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    string s,t;
    cin >> s >> t;
    int n = s.size();
    rep(i,n){
        if(s[i] != t[i]){
            cout << i+1<< endl;
            return 0;
        }
    }
    cout << n+1 << endl;
    return 0;
}