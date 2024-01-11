#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    string s,t;
    cin >> s >> t;
    bool ans = false;
    if(s.size() >= t.size()){
        rep(i,s.size()-t.size()+1){
            string ns = s.substr(i,t.size());
            if(ns == t){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}