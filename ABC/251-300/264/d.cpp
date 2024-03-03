#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    string s;
    cin >> s;
    string t = "atcoder";
    map<char,int> mp;
    rep(i,t.size()){
        mp[t[i]] = i;
    }
    int ans = 0;
    rep(i,s.size()){
        for(int j = i+1;j<s.size();j++){
            if(mp[s[i]] > mp[s[j]]) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}