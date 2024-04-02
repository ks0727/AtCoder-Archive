#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    string s;
    cin >> s;
    int n = s.size();
    set<string> st;
    rep(i,n){
        for(int j=i;j<(n);j++){
            string ns = s.substr(i,j-i+1);
            st.insert(ns);
        }
    }
    cout << st.size() << endl;
    return 0;
}