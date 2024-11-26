#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    vector<int> cnt(26);
    string s;
    cin >> s; 
    int n = s.size();
    if(n%2 == 1){
        cout << "No" << endl;
        return 0;
    }
    rep(i,n/2){
        if(s[2*i] != s[2*i+1]){
            cout << "No" << endl;
            return 0;
        }
        cnt[s[2*i]-'a']+=2;
    }
    rep(i,26){
        if(cnt[i] != 0 && cnt[i] != 2){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}