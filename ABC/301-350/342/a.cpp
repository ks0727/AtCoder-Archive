#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    string s;
    cin >> s;
    int size = s.size();
    int idx = -1;
    rep(i,size-1){
        if(s[i] != s[i+1]){
            idx = i;
            break;
        }
    }
    vector<int> cnt(26);
    rep(i,size){
        cnt[s[i]-'a']++;
    }
    int ans = idx;
    if(cnt[s[idx]-'a'] > cnt[s[idx+1]-'a']) ans = idx+1;
    cout << ans+1 << endl;
    return 0;
}