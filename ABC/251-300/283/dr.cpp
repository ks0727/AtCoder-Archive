#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    string s;
    cin >> s;
    int n = s.size();
    vector<set<char> > x(n);
    set<char> box;
    int now = 0;
    rep(i,n){
        if(s[i] == '(') now++;
        if(s[i] != '(' && s[i] != ')'){
            if(box.count(s[i])){
                cout << "No" << endl;
                return 0;
            }else{
                box.insert(s[i]);
                x[now].insert(s[i]);
            }
        }
        if(s[i] == ')'){
            for(auto xin : x[now]){
                if(box.count(xin)){
                    box.erase(xin);
                }
            }
            x[now].clear();
            now--;
        }
    }
    cout << "Yes" << endl;
    return 0;
}