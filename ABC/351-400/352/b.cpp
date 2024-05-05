#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    string s,t;
    cin >> s >> t;
    int now = 0;
    vector<int> ans;
    rep(i,t.size()){
        if(s[now] == t[i]){
            now++;
            ans.push_back(i+1);
        }
        if(now == s.size()) break;
    }
    for(int x : ans) cout << x << ' '; cout << endl;
    return 0;
}