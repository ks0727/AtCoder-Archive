#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

bool ok(string t, string  ns){
    rep(i,t.size()){
        if(t[i] == ns[i]) continue;
        if(t[i] != '?' && ns[i] != '?') return false;
    }
    return true;
}

int main(){
    string s,t;
    cin >> s >> t;
    string s1 = "";
    string s2 = s.substr(s.size()-t.size(),t.size());
    rep(x,t.size()+1){
        s1 += s[x];
        
        string ns = s1+s2;
        if(ok(t,ns)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}