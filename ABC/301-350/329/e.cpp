#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n,m;
    cin >> n >> m;
    string s,t;
    cin >> s >> t;
    if(s[0] != t[0] || s.back() != t.back()){
        cout << "No" << endl;
        return 0;
    }
    set<char> st;
    if(m >= 3){
        for(int i = 1;i<=(m-2);i++){
            if(t[i] != t[0] && t[i] != t[m-1]) st.insert(t[i]);
        }
    }
    rep(i,n){
        if(i == 0) continue;
        if(s[i] == s[i-1] && st.count(s[i])){
            cout << "No" << endl;
            return 0;
        }
    }
    bool ok = false;
    set<string> ex;
    string g = t;
    sort(g.begin(),g.end());
    do{
        ex.insert(g);
    }while(next_permutation(g.begin(),g.end()));
    string g(m,t[0]);
    rep(i,n-m+1){
        string ns = s.substr(i,m);
        if(!ok) {
            if(ns == t){
                ok = true;
            }
        }
        if(!ex.count(ns)){
            cout << "No" << endl;
            return 0;
        }
    }
    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}