#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    int n;
    cin >> n;
    vector<string> s(n);
    vector<int> t(n);
    rep(i,n) cin >> s[i] >> t[i];
    set<string> st;
    int now = 0;
    int ans = 0;
    rep(i,n){
        if(st.count(s[i])) continue;
        st.insert(s[i]);
        if(now < t[i]){
            ans = i;
            now= t[i];
        }
    }
    cout << ans + 1 << endl;
    return 0;
}