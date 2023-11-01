#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    string s;
    cin >> s;
    int n = s.size();
    vector<int> js;
    set<char> balls;
    stack<int> push_time;
    rep(i,n){
        if(s[i] == '('){
            js.push_back(i);
            continue;
        }
        if(s[i] == ')'){
            balls.clear();
        }
        if(s[i] != '(' && s[i] != ')'){
            if(balls.count(s[i])){
                cout << "No" << endl;
                return 0;
            }else{
                balls.insert(s[i]);
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}