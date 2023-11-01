#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    cin >> n;
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    set<string> st;
    int ans = 0;
    rep(i,n){
        if(st.count(s[i])){
            continue;
        }
        string s2 = s[i];
        reverse(s2.begin(),s2.end());
        if(st.count(s2)){
            continue;
        }
        ans++;
        st.insert(s[i]);
    }
    cout << ans << endl;
    return 0;
}