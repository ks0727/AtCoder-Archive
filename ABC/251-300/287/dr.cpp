#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    string s,t;
    cin >> s >> t;
    vector<bool> begin_ans(t.size()+1);
    vector<bool> end_ans(t.size()+1);
    bool ok = false;
    rep(i,t.size()){
        if(!ok) {
            if(s[i] == t[i] || s[i] == '?' || t[i] == '?'){
                begin_ans[i] = true;
            }
            ok = true;
        }else{
            begin_ans[i] = false;
        }
    }
    reverse(s.begin(),s.end());
    reverse(t.begin(),t.end());
    ok = false;
    rep(i,t.size()){
        if(!ok){
            if(s[i] == t[i] || s[i] == '?' || t[i] == '?'){
                end_ans[i] = true;
            }
            ok = true;
        }else{
            end_ans[i] = false;
        }
    }
    rep(i,t.size()+1){
        if(begin_ans[i] && end_ans[t.size()-i]){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }
    return 0;
}