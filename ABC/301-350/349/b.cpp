#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)

int main(){
    string s;
    cin >> s;
    vector<int> alph(26);
    rep(i,s.size()){
        alph[s[i]-'a'] += 1;
    }
    vector<int> cnt(101);
    rep(i,26){
        cnt[alph[i]]++;
    }
    bool good = true;
    for(int i=1;i<(101);i++){
        if(cnt[i] != 0 && cnt[i] != 2) good =false; 
    }
    if(good) cout << "Yes" << endl;
    else cout << "No" << endl; 
    return 0;
}