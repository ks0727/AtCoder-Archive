#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    stack<int> st;
    string ans = "";
    rep(i,n){
        if(s[i] == ')'){
            if(st.size() > 0){
                int x = st.top(); st.pop();
                rep(j,x){
                    ans.pop_back();
                }
            }else{
                ans += s[i];
            }
        }
        else if(s[i] == '('){
            ans += s[i];
            st.push(1);
        }
        else{
            ans += s[i];
            if(st.size() > 0) st.top()++;
        }
    }
    cout << ans << endl;
}