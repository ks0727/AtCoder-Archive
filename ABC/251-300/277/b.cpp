#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

bool ok(string s){
    bool ret = true;
    if(s[0] != 'H' && s[0] != 'D' && s[0] != 'C' && s[0] != 'S') return false; 
    string two = " A23456789TJQK ";
    bool tok = false;
    rep(i,two.size()){
        if(s[1] == two[i]){
            tok = true;
            break;
        }
    }
    if(!tok) return false;
    return true;
};

int main(){
    int n;
    cin >> n;
    bool ans = true;
    set<string> st;
    rep(i,n){
        string s;
        cin >> s;
        if(!ok(s)) ans = false;
        if(st.count(s)) ans = false;
        st.insert(s);
    }
    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}