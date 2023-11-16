#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<string> x(n);
    int now = 0;
    string ans = "";
    rep(i,n){
        if(s[i] == ')' && now == 0){
            ans += s[i];
        }
        else if(s[i] == ')' && now > 0){
            rep(j,x[now].size()) ans.pop_back();
            x[now] = "";
            now--;
        }
        else if(s[i] == '('){
            ans += s[i];
            now++;
            x[now].push_back('(');
        }
        else{
            ans += s[i];
            x[now].push_back(s[i]);
        }
    }
    cout << ans << endl;
}