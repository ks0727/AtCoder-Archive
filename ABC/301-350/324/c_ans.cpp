#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

bool check(string s, string t){
    if(s.size() > t.size()) return check(t,s);
    if(s.size() < t.size() - 1) return false;
    int i = 0,j = 0,miss = 0;
    while(i < s.size()){
        if(s[i] == t[j]){
            i++; j++;
        }else{
            miss++;
            if(miss > 1) return false;
            if(s.size() == t.size()) i++;
            j++;
        }
    }
    return true;
}

int main(){
    int n;
    cin >> n;
    string t;
    cin >> t;
    vector<int> ans;
    rep(i,n){
        string s;
        cin >> s;
        if(check(s,t)) ans.push_back(i+1);
    }
    cout << ans.size() << endl;
    rep(i,ans.size()) cout << ans[i] << ' ';
    return 0;
}