#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    string s;
    cin >> s;
    stack<int> st;
    map<char,int> mp;
    mp['['] = 1;
    mp[']'] = -1;
    mp['('] = 2;
    mp[')'] = -2;
    mp['<'] = 3;
    mp['>'] = -3;
    rep(i,s.size()){
        if(st.size() == 0 || mp[s[i]] > 0) st.push(mp[s[i]]);
        else{
            if(mp[s[i]] == -st.top()) st.pop();
            else st.push(mp[s[i]]);
        }
    }

    if(st.size() == 0) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}