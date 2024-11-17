#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    string s;
    cin >> s;
    vector<int> ans;
    rep(i,s.size()){
        if(i == s.size() -1) break;
        int cnt = 0;
        if(s[i] == '|'){
            int j = i+1;
            while(s[j] != '|'){
                cnt++;
                j++;
            }
            i = j-1;
        }
        ans.push_back(cnt);
    }
    for(int x : ans) cout << x << ' '; cout << endl;
    return 0;
}