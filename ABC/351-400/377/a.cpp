#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    string s;
    cin >> s;
    set<char> st;
    rep(i,s.size()) st.insert(s[i]);
    string abc = "ABC";
    rep(i,s.size()){
        if(!st.count(abc[i])){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}