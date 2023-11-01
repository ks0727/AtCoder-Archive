#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

string rev(string s){
    reverse(s.begin(),s.end());
    return s;
}

int main(){
    int n;
    cin >> n;
    set<string> st;
    rep(i,n){
        string s;
        cin >> s;
        if(st.count(s)) continue;
        if(st.count(rev(s))) continue;
        st.insert(s);
    }

    cout << st.size() << endl;
    return 0;
}